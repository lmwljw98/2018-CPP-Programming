// C++ BattleShip 프로젝트
// 작성 일자: 2018-05-31
// 학번 : 20171676
// 이름 : 이정우
#pragma once
#include "Defender.h"
#include "Attacker.h"
#include "GameBoard.h"

// GameManager 정의. 게임 플레이어, 게임 보드, 여러 정보들을 관리
class GameManager{
private:
    GameBoard m_gameboard; // GameBoard 생성
    Defender m_defender; // Defender 생성
    Attacker m_attacker; // Attacker 생성
    int turn; // 현재 턴을 저장할 변수
public:
    GameManager(); // 생성자
    void play(); // 게임 시작 함수
    bool allDestroy(); // 모든 배가 파괴되었는지 여부 확인하는 함수. 모두 파괴되었으면 true 리턴.
};
