// C++ BattleShip 프로젝트
// 작성 일자: 2018-05-31
// 학번 : 20171676
// 이름 : 이정우
#pragma once
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"

// Defender 정의
class Defender {
    friend class GameManager; // GameManager 클래스가 Defender의 private 멤버 변수에 접근 가능하도록 함
private:
    Aircraft m_aircraft; // Aircraft 객체 생성
    Battleship m_battleship; // Battleship 객체 생성
    Cruiser m_cruiser; // Cruiser 객체 생성
    Destroyer m_destroyer; // Destroyer 객체 생성
    Destroyer m_destroyer2; // Destroyer 객체 생성
    int dMap[8][8]; // Defender 맵 배열
public:
    Defender(); // 생성자
    void locateShips(); // Defender가 가진 배를 모두 랜덤 배치함
};
