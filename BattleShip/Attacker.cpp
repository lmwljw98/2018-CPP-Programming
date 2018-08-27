// C++ BattleShip 프로젝트
// 작성 일자: 2018-05-31
// 학번 : 20171676
// 이름 : 이정우
#include "Attacker.h"

// Attacker 맵 배열 초기화
Attacker::Attacker(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            aMap[i][j] = 0;
        }
    }
}
