#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int check(int [][7], int, int, int);
int main(){
    int numTestCases = 0;
    ifstream inStream;
    inStream.open("input.txt");

    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++){
        int m = 0;
        bool state = false;
        int num; inStream >> num;
        int* numlist = new int[num];
        for(int j = 0; j < num; j++){
            inStream >> numlist[j];
        }
        int map[6][7] = {0};

        for(int j = 1; j < num+1; j++){
            for(int row = 5; row >= 0; row--){
                if(map[row][numlist[j-1] - 1] == 0){
                    if(j % 2 == 0) { map[row][numlist[j-1] - 1] = 2; }
                    else { map[row][numlist[j-1] - 1] = 1; }
                    break;
                }
            }
        }

        for(int row = 0; row < 6; row++){
            for(int col = 0; col < 7; col++){
                if(map[row][col] == 1 || map[row][col] == 2){
                    m = check(map, map[row][col], row, col);
                    if(m > 0){
                        cout << m << endl;
                        state = true;
                        break;
                    }
                }
            }
            if(state) break;
        }
        if(!state) cout << 0 << endl;
    }
    inStream.close();
}

int check(int map[][7], int stone, int row, int col){
    // 가로
    if(col + 3 < 7){
        if(map[row][col] == stone && map[row][col+1] == stone && map[row][col+2] == stone && map[row][col+3] == stone){
            return stone;
        }
    }
    // 세로
    if(row + 3 < 6){
        if(map[row][col] == stone && map[row+1][col] == stone && map[row+2][col] == stone && map[row+3][col] == stone){
            return stone;
        }
    }
    // 대각선
    if(row + 3 < 6 && col + 3 < 7){
        if(map[row][col] == stone && map[row+1][col+1] == stone && map[row+2][col+2] == stone && map[row+3][col+3] == stone){
            return stone;
        }
    }
    if(row + 3 < 6 && col - 3 > -1){
        if(map[row][col] == stone && map[row+1][col-1] == stone && map[row+2][col-2] == stone && map[row+3][col-3] == stone){
            return stone;
        }
    }
    return -1;
}
