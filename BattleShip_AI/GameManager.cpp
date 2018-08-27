// C++ BattleShip 프로젝트
// 작성 일자: 2018-05-31
// 수정 일자(AI ver.): 2018-06-05
// 학번 : 20171676
// 이름 : 이정우
#include "GameManager.h"
#include <unistd.h>

GameManager::GameManager(){
    turn = 0; // 현재 턴을 0으로 초기화
}

int GameManager::play(int game, int delay){
    m_gameboard.init(game); // 기초 세팅 초기화
    m_gameboard.render(); // 화면에 게임판 출력
    m_defender.locateShips(); // 수비자는 배를 랜덤한 곳에 배치
    m_gameboard.refreshDefenderMap(m_defender.dMap); // Defender 맵 초기화
    m_gameboard.refreshAttackerMap(m_attacker.aMap); // Attacker 맵 초기화
    m_gameboard.refreshStatus(0, false, false, false, false, false); // Status 초기화
    while(!allDestroy()){ // 모든 배가 파괴될때 까지 게임 진행
        m_attacker.setRandomPosition(m_gameboard.position);
        bool isCorrect = m_gameboard.inputAttack(m_gameboard.position, m_defender.dMap, m_attacker.aMap); // 좌표 input
        if(isCorrect) turn++; // 잘못된 입력이 아니면 턴 수 증가

        // 변경된 상태 refresh
        m_gameboard.refreshStatus(turn,
            m_defender.m_aircraft.isDestroy(m_attacker.aMap), m_defender.m_battleship.isDestroy(m_attacker.aMap),
            m_defender.m_cruiser.isDestroy(m_attacker.aMap), m_defender.m_destroyer.isDestroy(m_attacker.aMap),
            m_defender.m_destroyer2.isDestroy(m_attacker.aMap) );

        m_gameboard.refreshAttackerMap(m_attacker.aMap); // 공격자 맵 refresh
        usleep(delay * 1000);
    }
    m_gameboard.exitGame(); // 게임 종료
    return turn;
}

bool GameManager::allDestroy(){
    // 각각의 배가 모두 파괴되었는지 확인
    if(m_defender.m_aircraft.isDestroy(m_attacker.aMap) && m_defender.m_battleship.isDestroy(m_attacker.aMap)
    && m_defender.m_cruiser.isDestroy(m_attacker.aMap) && m_defender.m_destroyer.isDestroy(m_attacker.aMap)
    && m_defender.m_destroyer2.isDestroy(m_attacker.aMap)){
        return true;
    }
    else return false;
}
