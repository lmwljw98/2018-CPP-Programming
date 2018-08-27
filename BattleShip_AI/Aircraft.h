// C++ BattleShip 프로젝트
// 작성 일자: 2018-05-31
// 학번 : 20171676
// 이름 : 이정우
#pragma once
#include "Ship.h"

// Aircraft 배 정의, Ship 클래스를 상속받음
class Aircraft : public Ship{
public:
    Aircraft(); // 생성자
    void locate(int [][8]); // 배를 랜덤한 곳에 배치하는 함수
};
