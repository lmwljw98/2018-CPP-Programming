// C++ BattleShip 프로젝트
// 작성 일자: 2018-05-31
// 학번 : 20171676
// 이름 : 이정우
#pragma once
#include <ctime>
#include <iostream>

// Ship 클래스 정의. 각 배의 공통된 속성을 정의한다.
class Ship{
protected:
    int size; // 배의 크기
    int row_location[5]; // 배의 위치를 저장핣 배열
    int col_location[5]; // 배의 위치를 저장할 배열
    const int MAP_SIZE = 8; // 맵 크기
public:
    bool isDestroy(int [][8]); // 배의 파괴 여부를 리턴하는 함수
};
