// C++ BattleShip 프로젝트
// 작성 일자: 2018-05-31
// 학번 : 20171676
// 이름 : 이정우
#include "Battleship.h"

// 멤버 변수 초기화
Battleship::Battleship(){
    size = 4;
    for(int i = 0; i < size; i++){
        row_location[i] = -1;
        col_location[i] = -1;
    }
}

void Battleship::locate(int dMap[][8]){
    srand((unsigned int)time(NULL)); // 랜덤 시드
    bool isVertical; // 가로 배치, 세로 배치 여부 확인 변수
    int row;
    int col;
    int idx = 0;

    while(true){
        int locateType = rand() % 100 + 1; // 가로, 세로 배치 랜덤 결정
        if(locateType % 2 == 0) { isVertical = false; } // 가로 배치
        else { isVertical = true; } // 세로 배치

        row = rand() % MAP_SIZE; // 0~7 값이 랜덤으로 결정
        col = rand() % MAP_SIZE; // 0~7 값이 랜덤으로 결정

        if(dMap[row][col] > 0) continue; // 최초로 선택된 좌표에 이미 배가 있다면 좌표를 다시 결정함

        // 가로 배치
        if(!isVertical){
            if(col <= 2){
                // 오른쪽
                if(dMap[row][col] == 0 && dMap[row][col+1] == 0 && dMap[row][col+2] == 0 && dMap[row][col+3] == 0){
                    for(int i = col; i < col + size; i++){
                        dMap[row][i] = 2; // Defender 맵 배열에 저장
                        row_location[idx] = row;
                        col_location[idx] = i;
                        idx++;
                    }
                    break;
                }
                else continue;
            }
            else if(col <= 4){
                // 오른쪽
                if(dMap[row][col] == 0 && dMap[row][col+1] == 0 && dMap[row][col+2] == 0 && dMap[row][col+3] == 0){
                    for(int i = col; i < col + size; i++){
                        dMap[row][i] = 2; // Defender 맵 배열에 저장
                        row_location[idx] = row;
                        col_location[idx] = i;
                        idx++;
                    }
                    break;
                }
                // 왼쪽
                else if(dMap[row][col] == 0 && dMap[row][col-1] == 0 && dMap[row][col-2] == 0 && dMap[row][col-3] == 0){
                    for(int i = col; i > col - size; i--){
                        dMap[row][i] = 2; // Defender 맵 배열에 저장
                        row_location[idx] = row;
                        col_location[idx] = i;
                        idx++;
                    }
                    break;
                }
                else continue;
            }
            else{
                // 왼쪽
                if(dMap[row][col] == 0 && dMap[row][col-1] == 0 && dMap[row][col-2] == 0 && dMap[row][col-3] == 0){
                    for(int i = col; i > col - size; i--){
                        dMap[row][i] = 2; // Defender 맵 배열에 저장
                        row_location[idx] = row;
                        col_location[idx] = i;
                        idx++;
                    }
                    break;
                }
                else continue;
            }
        }

        // 세로 배치
        else{
            if(row <= 2){
                // 아래쪽
                if(dMap[row][col] == 0 && dMap[row+1][col] == 0 && dMap[row+2][col] == 0 && dMap[row+3][col] == 0){
                    for(int i = row; i < row + size; i++){
                        dMap[i][col] = 2; // Defender 맵 배열에 저장
                        row_location[idx] = i;
                        col_location[idx] = col;
                        idx++;
                    }
                    break;
                }
                else continue;
            }
            else if(row <= 4){
                // 아래쪽
                if(dMap[row][col] == 0 && dMap[row+1][col] == 0 && dMap[row+2][col] == 0 && dMap[row+3][col] == 0){
                    for(int i = row; i < row + size; i++){
                        dMap[i][col] = 2; // Defender 맵 배열에 저장
                        row_location[idx] = i;
                        col_location[idx] = col;
                        idx++;
                    }
                    break;
                }
                // 위쪽
                else if(dMap[row][col] == 0 && dMap[row-1][col] == 0 && dMap[row-2][col] == 0 && dMap[row-3][col] == 0){
                    for(int i = row; i > row - size; i--){
                        dMap[i][col] = 2; // Defender 맵 배열에 저장
                        row_location[idx] = i;
                        col_location[idx] = col;
                        idx++;
                    }
                    break;
                }
                else continue;
            }
            else{
                // 위쪽
                if(dMap[row][col] == 0 && dMap[row-1][col] == 0 && dMap[row-2][col] == 0 && dMap[row-3][col] == 0){
                    for(int i = row; i > row - size; i--){
                        dMap[i][col] = 2; // Defender 맵 배열에 저장
                        row_location[idx] = i;
                        col_location[idx] = col;
                        idx++;
                    }
                    break;
                }
                else continue;
            }
        }
    }
}
