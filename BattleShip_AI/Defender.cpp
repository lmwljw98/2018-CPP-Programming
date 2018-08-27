// C++ BattleShip 프로젝트
// 작성 일자: 2018-05-31
// 학번 : 20171676
// 이름 : 이정우
#include "Defender.h"

// Defender 맵 배열 초기화
Defender::Defender(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            dMap[i][j] = 0;
        }
    }
}

void Defender::locateShips(){
    m_aircraft.locate(dMap); // Aircraft 배치
    m_battleship.locate(dMap); // Battleship 배치
    m_cruiser.locate(dMap); // Cruiser 배치
    m_destroyer.locate(dMap); // Destroyer 배치
    m_destroyer2.locate(dMap); // Destroyer 배치
}
