// C++ BattleShip 프로젝트
// 작성 일자: 2018-05-31
// 학번 : 20171676
// 이름 : 이정우
#include "Aircraft.h"

// 멤버 변수 초기화
Aircraft::Aircraft(){
    size = 5;
    for(int i = 0; i < size; i++){
        row_location[i] = -1;
        col_location[i] = -1;
    }
}

void Aircraft::locate(int dMap[][8]){
    srand((unsigned int)time(NULL)); // 랜덤 시드
    bool isVertical; // 가로 배치, 세로 배치 여부 확인 변수
    int locateType = rand() % 100 + 1; // 가로, 세로 배치 랜덤 결정
    if(locateType % 2 == 0) { isVertical = false; } // 가로 배치
    else { isVertical = true; } // 세로 배치

    int row = rand() % MAP_SIZE; // 0~7 값이 랜덤으로 결정
    int col = rand() % MAP_SIZE; // 0~7 값이 랜덤으로 결정
    int idx = 0; // 위치 저장 배열의 인덱스

    // 가로 배치
    if(!isVertical){
        // 오른쪽으로 배치
        if(col <= 3){
            for(int i = col; i < col + size; i++){
                dMap[row][i] = 1; // Defender 맵 배열에 저장
                row_location[idx] = row;
                col_location[idx] = i;
                idx++;
            }
        }
        // 왼쪽으로 배치
        else{
            for(int i = col; i > col - size; i--){
                dMap[row][i] = 1; // Defender 맵 배열에 저장
                row_location[idx] = row;
                col_location[idx] = i;
                idx++;
            }
        }
    }

    // 세로 배치
    else{
        // 아래쪽으로 배치
        if(row <= 3){
            for(int i = row; i < row + size; i++){
                dMap[i][col] = 1; // Defender 맵 배열에 저장
                row_location[idx] = i;
                col_location[idx] = col;
                idx++;
            }
        }
        // 위쪽으로 배치
        else{
            for(int i = row; i > row - size; i--){
                dMap[i][col] = 1; // Defender 맵 배열에 저장
                row_location[idx] = i;
                col_location[idx] = col;
                idx++;
            }
        }
    }
}
