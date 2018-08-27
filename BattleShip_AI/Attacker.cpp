// C++ BattleShip 프로젝트
// 작성 일자: 2018-05-31
// 수정 일자(AI ver.): 2018-06-05
// 학번 : 20171676
// 이름 : 이정우
#include "Attacker.h"
#include <ctime>
#include <iostream>

// Attacker 맵 배열 초기화
Attacker::Attacker(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            aMap[i][j] = 0;
        }
    }
    direction = 0;
}

void Attacker::setRandomPosition(char* position){
    srand((unsigned int)time(NULL)); // 랜덤 시드
    int row = position[0] - 'A';
    int col = (position[1] - '0') - 1;

    if(aMap[row][col] == 0){
        position[0] = row + 'A';
        position[1] = col + '1';
    }
    else if(aMap[row][col] == -1){
        if(row_history.empty() && col_history.empty()){
            while(true){
                row = rand() % MAP_SIZE;
                col = rand() % MAP_SIZE;
                if(aMap[row][col] == 0) break;
            }
            direction = 0;
        }
        else{
            row = row_history[0];
            col = col_history[0];
            direction++;
            if(direction % 4 == 0){
                if(row == 0) direction++;
                else{
                    if(aMap[row-1][col] == 0) row--;
                    else{
                        row = row_history[0];
                        col = col_history[0];
                        direction++;
                    }
                }
            }
            if(direction % 4 == 1){
                if(col == 7) direction++;
                else {
                    if(aMap[row][col+1] == 0) col++;
                    else{
                        row = row_history[0];
                        col = col_history[0];
                        direction++;
                    }
                }
            }
            if(direction % 4 == 2){
                if(row == 7) direction++;
                else {
                    if(aMap[row+1][col] == 0) row++;
                    else{
                        row = row_history[0];
                        col = col_history[0];
                        direction++;
                    }
                }
            }
            if(direction % 4 == 3){
                if(col == 0) {
                    while(true){
                        row = rand() % MAP_SIZE;
                        col = rand() % MAP_SIZE;
                        if(aMap[row][col] == 0) break;
                    }
                }
                else {
                    if(aMap[row][col-1] == 0) col--;
                    else {
                        while(true){
                            row = rand() % MAP_SIZE;
                            col = rand() % MAP_SIZE;
                            if(aMap[row][col] == 0) break;
                        }
                    }
                }
                direction++;
                row_history.clear();
                col_history.clear();
            }
        }
        position[0] = row + 'A';
        position[1] = col + '1';
    }
    else if(aMap[row][col] == 1){
        row_history.push_back(row);
        col_history.push_back(col);
        if(direction % 4 == 0){
            if(row == 0) {
                row = row_history[0];
                col = col_history[0];
                direction++;
            }
            else{
                if(aMap[row-1][col] == 0) row--;
                else{
                    row = row_history[0];
                    col = col_history[0];
                    direction++;
                }
            }
        }
        if(direction % 4 == 1){
            if(col == 7) {
                row = row_history[0];
                col = col_history[0];
                direction++;
            }
            else {
                if(aMap[row][col+1] == 0) col++;
                else{
                    row = row_history[0];
                    col = col_history[0];
                    direction++;
                }
            }
        }
        if(direction % 4 == 2){
            if(row == 7) {
                row = row_history[0];
                col = col_history[0];
                direction++;
            }
            else {
                if(aMap[row+1][col] == 0) row++;
                else{
                    row = row_history[0];
                    col = col_history[0];
                    direction++;
                }
            }
        }
        if(direction % 4 == 3){
            if(col == 0) {
                while(true){
                    row = rand() % MAP_SIZE;
                    col = rand() % MAP_SIZE;
                    if(aMap[row][col] == 0) break;
                }
                direction++;
                row_history.clear();
                col_history.clear();
            }
            else {
                if(aMap[row][col-1] == 0) col--;
                else {
                    while(true){
                        row = rand() % MAP_SIZE;
                        col = rand() % MAP_SIZE;
                        if(aMap[row][col] == 0) break;
                    }
                    direction++;
                    row_history.clear();
                    col_history.clear();
                }
            }
        }
        position[0] = row + 'A';
        position[1] = col + '1';
    }
}
