// C++ BattleShip 프로젝트
// 작성 일자: 2018-05-31
// 학번 : 20171676
// 이름 : 이정우
#pragma once

// Attacker 정의
class Attacker {
    friend class GameManager; // GameManager 클래스가 Attacker의 private 멤버 변수에 접근 가능하도록 함
private:
    int aMap[8][8]; // Attacker 맵 배열
public:
    Attacker(); // 생성자
};
