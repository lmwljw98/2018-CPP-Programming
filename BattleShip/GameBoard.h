// C++ BattleShip 프로젝트
// 작성 일자: 2018-05-31
// 학번 : 20171676
// 이름 : 이정우
#pragma once
#include <ncurses.h>

// GameBoard 정의. 게임판 출력, 입력 확인 담당.
class GameBoard{
private:
    WINDOW *DEFENDER; // Defender 맵 윈도우
    WINDOW *ATTACKER; // Attacker 맵 윈도우
    WINDOW *STATUS; // Status 윈도우
    WINDOW *INPUT; // Input 윈도우
    WINDOW *RESULT; // Input Result 윈도우
    char position[2]; // Position input 저장 변수
    const int MAP_SIZE = 8; // 맵 크기
public:
    void init(); // 기초 세팅 초기화

    // 전체적인 판을 그리는 함수
    void render();
    void drawDefenderMap();
    void drawAttackerMap();
    void drawStatusWindow();
    void drawInputWindow();

    void refreshDefenderMap(int [][8]); // Defender 윈도우를 refresh하는 함수
    void refreshAttackerMap(int [][8]); // Attacker 윈도우를 refresh하는 함수
    bool inputAttack(int [][8], int [][8]); // 좌표 입력을 받아 Hit, Miss 여부를 확인, 잘못된 입력이면 false 리턴
    bool checkHit(int, int, int [][8]); // 좌표가 Hit이면 true, Miss이면 false 리턴
    void refreshInput(const char*); // Input 윈도우를 refresh하는 함수
    void refreshStatus(int, bool, bool, bool, bool, bool); // Status 윈도우를 refresh하는 함수
    void exitGame(); // 게임을 종료하는 함수
};
