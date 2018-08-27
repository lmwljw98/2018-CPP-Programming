// C++ BattleShip 프로젝트
// 작성 일자: 2018-05-31
// 수정 일자(AI ver.): 2018-06-05
// 학번 : 20171676
// 이름 : 이정우
#include <clocale>
#include "GameBoard.h"

GameBoard::GameBoard(){
    position[0] = 'D';
    position[1] = '4';
}

void GameBoard::init(int game){
    initscr();
    resize_term(29, 70); // 콘솔 사이즈 조정
    start_color(); // 색 사용
    init_pair(1, COLOR_WHITE, COLOR_BLUE); // 색 프리셋 저장
    init_pair(2, COLOR_WHITE, COLOR_RED); // 색 프리셋 저장
    init_pair(3, COLOR_WHITE, COLOR_MAGENTA); // 색 프리셋 저장
    border('*', '*', '*', '*', '*', '*', '*', '*'); // 테두리 지정
    mvprintw(1, 1, "BATTLESHIP GAME");
    mvprintw(2, 1, "GAME - ");
    mvprintw(2, 8, "%d", game);
}

void GameBoard::render() {
    drawDefenderMap(); // Defender 맵을 그림
    drawAttackerMap(); // Attacker 맵을 그림
    drawStatusWindow(); // Status 윈도우를 그림
    drawInputWindow(); // Input 윈도우를 그림

    // 출력
    refresh();
    wrefresh(DEFENDER);
    wrefresh(ATTACKER);
    wrefresh(STATUS);
    wrefresh(INPUT);
    wrefresh(RESULT);
}

void GameBoard::drawDefenderMap(){
    DEFENDER = newwin(10, 10, 3, 5); // Defender 윈도우 생성
    wbkgd(DEFENDER, COLOR_PAIR(1));
    wattron(DEFENDER, COLOR_PAIR(1));
    box(DEFENDER, 0, 0);
    mvwprintw(DEFENDER, 0, 1, "DEFENDER");

    // 행, 열 표현
    for(int i = 0; i < MAP_SIZE; i++){
        mvprintw(i+4, 4, "%c", 'A' + i);
        mvprintw(13, i+6, "%c", '1' + i);
    }
}

void GameBoard::drawAttackerMap(){
    ATTACKER = newwin(10, 10, 16, 5); // Attacker 윈도우 생성
    wbkgd(ATTACKER, COLOR_PAIR(1));
    wattron(ATTACKER, COLOR_PAIR(1));
    box(ATTACKER, 0, 0);
    mvwprintw(ATTACKER, 0, 1, "ATTACKER");

    // 행, 열 표현
    for(int i = 0; i < MAP_SIZE; i++){
        mvprintw(i+17, 4, "%c", 'A' + i);
        mvprintw(26, i+6, "%c", '1' + i);
    }
}

void GameBoard::drawStatusWindow(){
    STATUS = newwin(8, 30, 3, 27); // Status 윈도우 생성
    wbkgd(STATUS, COLOR_PAIR(2));
    wattron(STATUS, COLOR_PAIR(2));
    box(STATUS, 0, 0);
    mvwprintw(STATUS, 0, 1, "STATUS");
}

void GameBoard::drawInputWindow(){
    INPUT = newwin(2, 20, 16, 27); // Input 윈도우 생성
    wbkgd(INPUT, COLOR_PAIR(3));
    wattron(INPUT, COLOR_PAIR(3));
    box(INPUT, 0, 0);
    mvwprintw(INPUT, 0, 1, "INPUT (EX: A3)");
    //mvwprintw(INPUT, 1, 1, "Input position: ");
    mvwprintw(INPUT, 1, 1, "AI Playing..");

    RESULT = newwin(1, 20, 19, 27); // Result 윈도우 생성
    wbkgd(RESULT, COLOR_PAIR(3));
    wattron(RESULT, COLOR_PAIR(3));
}

void GameBoard::refreshDefenderMap(int dMap[][8]){
    //wclear(DEFENDER); // Defender 윈도우 내용 삭제
    //box(DEFENDER, 0, 0);
    //mvwprintw(DEFENDER, 0, 1, "DEFENDER");
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            // Defender의 맵을 탐색하며 각각의 배를 출력
            if(dMap[i][j] == 0){
                mvwprintw(DEFENDER, i+1, j+1, ".");
            }
            else if(dMap[i][j] == 1){
                mvwprintw(DEFENDER, i+1, j+1, "A");
            }
            else if(dMap[i][j] == 2){
                mvwprintw(DEFENDER, i+1, j+1, "B");
            }
            else if(dMap[i][j] == 3){
                mvwprintw(DEFENDER, i+1, j+1, "C");
            }
            else if(dMap[i][j] == 4){
                mvwprintw(DEFENDER, i+1, j+1, "D");
            }
        }
    }
    wrefresh(DEFENDER);
}

void GameBoard::refreshAttackerMap(int aMap[][8]){
    //wclear(ATTACKER); // Attacker 윈도우 내용 삭제
    //box(ATTACKER, 0, 0);
    //mvwprintw(ATTACKER, 0, 1, "ATTACKER");
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            // Attacker 맵을 탐색하며 상태 출력
            if(aMap[i][j] == 0){
                mvwprintw(ATTACKER, i+1, j+1, ".");
            }
            else if(aMap[i][j] == -1){
                mvwprintw(ATTACKER, i+1, j+1, "M");
            }
            else if(aMap[i][j] == 1){
                mvwprintw(ATTACKER, i+1, j+1, "H");
            }
        }
    }
    wrefresh(ATTACKER);
}

bool GameBoard::inputAttack(const char* position, int dMap[][8], int aMap[][8]){
    // 입력 받음
    /*
    keypad(INPUT, false);
    curs_set(2);
    echo();
    mvwscanw(INPUT, 1, 17, "%s", position);
    */

    int row = position[0] - 'A';
    int col = (position[1] - '0') - 1;

    if((row >= 0 && row <= 7) && (col >= 0 && col <= 7)){ // 잘못된 입력 여부 확인
        bool isHit = checkHit(row, col, dMap); // Hit인지 아닌지 확인
        if(isHit){ // Hit일 경우
            refreshInput(position);
            mvwprintw(RESULT, 0, 3, " - ");
            mvwprintw(RESULT, 0, 6, "HIT!");
            aMap[row][col] = 1; // Hit 상태 표시
            dMap[row][col] = -1; // Hit 상태 표시
        }
        else{ // Miss일 경우
            refreshInput(position);
            mvwprintw(RESULT, 0, 3, " - ");
            if(dMap[row][col] == -1) { // 이미 Hit된 곳일 경우
                mvwprintw(RESULT, 0, 6, "Already HIT!");
            }
            else {
                mvwprintw(RESULT, 0, 6, "MISS!");
                aMap[row][col] = -1; // Miss 상태 표시
            }
        }
    }
    /*
    else{ // 잘못된 입력일 경우
        wclear(INPUT);
        wclear(RESULT);
        box(INPUT, 0, 0);
        mvwprintw(INPUT, 0, 1, "INPUT (EX: A3)");
        mvwprintw(INPUT, 1, 1, "Input position: ");
        mvwprintw(RESULT, 0, 1, "Invalid input");
        wrefresh(INPUT);
        wrefresh(RESULT);
        return false;
    }
    */
    //wrefresh(INPUT);
    wrefresh(RESULT);
    return true;
}

bool GameBoard::checkHit(int row, int col, int dMap[][8]){
    if(dMap[row][col] > 0) return true; // Hit이면 true 리턴
    else return false;
}

void GameBoard::refreshInput(const char* position){
    //wclear(INPUT);
    //wclear(RESULT);
    //box(INPUT, 0, 0);
    //mvwprintw(INPUT, 0, 1, "INPUT (EX: A3)");
    //mvwprintw(INPUT, 1, 1, "Input position: ");
    mvwprintw(RESULT, 0, 1, position);
}

void GameBoard::refreshStatus(int turn, bool aircraft_destroy, bool battleship_destroy, bool cruiser_destroy, bool destroyer_destroy, bool destroyer2_destroy){
    //wclear(STATUS);
    //box(STATUS, 0, 0);
    mvwprintw(STATUS, 0, 1, "STATUS");
    mvwprintw(STATUS, 1, 1, "TURN: ");
    mvwprintw(STATUS, 1, 7, "%d", turn);

    mvwprintw(STATUS, 2, 1, "AIRCRAFT: ");
    if(!aircraft_destroy) { mvwprintw(STATUS, 2, 11, "AAAAA"); } // 파괴되지 않은 경우
    else { mvwprintw(STATUS, 2, 11, "DESTROYED"); } // 파괴된 경우

    mvwprintw(STATUS, 3, 1, "BATTLESHIP: ");
    if(!battleship_destroy) { mvwprintw(STATUS, 3, 13, "BBBB"); } // 파괴되지 않은 경우
    else { mvwprintw(STATUS, 3, 13, "DESTROYED"); } // 파괴된 경우

    mvwprintw(STATUS, 4, 1, "CRUISER: ");
    if(!cruiser_destroy) { mvwprintw(STATUS, 4, 10, "CCC"); } // 파괴되지 않은 경우
    else { mvwprintw(STATUS, 4, 10, "DESTROYED"); } // 파괴된 경우

    mvwprintw(STATUS, 5, 1, "DESTROYER 1: ");
    if(!destroyer_destroy) { mvwprintw(STATUS, 5, 14, "DD"); } // 파괴되지 않은 경우
    else { mvwprintw(STATUS, 5, 14, "DESTROYED"); } // 파괴된 경우

    mvwprintw(STATUS, 6, 1, "DESTROYER 2: ");
    if(!destroyer2_destroy) { mvwprintw(STATUS, 6, 14, "DD"); } // 파괴되지 않은 경우
    else { mvwprintw(STATUS, 6, 14, "DESTROYED"); } // 파괴된 경우

    wrefresh(STATUS);
}

// 게임 종료
void GameBoard::exitGame(){
    //mvprintw(15, 5, "GAME END - Press ANY KEY to Exit Game."); // 게임 종료 메세지 출력
    //refresh();
    //getch();
    delwin(DEFENDER);
    delwin(ATTACKER);
    delwin(STATUS);
    delwin(INPUT);
    delwin(RESULT);
    endwin();
}
