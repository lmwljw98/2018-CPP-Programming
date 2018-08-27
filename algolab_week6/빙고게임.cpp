#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void find(int [][5], int);
bool check(int [][5]);
int main(){
    int numTestCases = 0;
    ifstream inStream;
    inStream.open("input.txt");

    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++){
        int map[5][5];
        int num[75]; int count = 0;
        for(int row = 0; row < 5; row++){
            for(int col = 0; col < 5; col++){
                inStream >> map[row][col];
            }
        }
        map[2][2] = 100;
        for(int j = 0; j < 75; j++){
            inStream >> num[j];
        }
        for(int j = 0; j < 75; j++){
            find(map, num[j]);
            count++;
            if(check(map)){
                break;
            }
        }
        cout << count << endl;
    }
    inStream.close();
}

void find(int map[][5], int num){
    for(int row = 0; row < 5; row++){
        for(int col = 0; col < 5; col++){
            if(map[row][col] == num){
                map[row][col] = 100;
            }
        }
    }
}

bool check(int map[][5]){
    for(int row = 0; row < 5; row++){
        if(map[row][0] == 100 && map[row][1] == 100 && map[row][2] == 100 && map[row][3] == 100 && map[row][4] == 100){
            return true;
        }
    }
    for(int col = 0; col < 5; col++){
        if(map[0][col] == 100 && map[1][col] == 100 && map[2][col] == 100 && map[3][col] == 100 && map[4][col] == 100){
            return true;
        }
    }
    if(map[0][0] == 100 && map[1][1] == 100 && map[2][2] == 100 && map[3][3] == 100 && map[4][4] == 100){
        return true;
    }
    if(map[0][4] == 100 && map[1][3] == 100 && map[2][2] == 100 && map[3][1] == 100 && map[4][0] == 100){
        return true;
    }

    if(map[0][0] == 100 && map[0][4] == 100 && map[4][0] == 100 && map[4][4] == 100){
        return true;
    }

    return false;
}
