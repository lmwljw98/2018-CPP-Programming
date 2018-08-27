// C++ BattleShip 프로젝트
// 작성 일자: 2018-05-31
// 학번 : 20171676
// 이름 : 이정우
#include "Ship.h"

// 모두 HIT 상태면 true, 아니면 false 리턴
bool Ship::isDestroy(int aMap[][8]){
    for(int i = 0; i < size; i++){
        if(aMap[row_location[i]][col_location[i]] != 1){
            return false;
        }
    }
    return true;
}
