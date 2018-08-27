#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

char map[100][100];
char temp[100][100];
bool isLiving(int, int, int, int);
int livingCellCount(int, int, int, int);
void changeMap(int, int);

int main(){
    int numTestCases = 0;
    ifstream inStream;
    inStream.open("input.txt");

    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++){
        int rowCount, colCount, generation;
        inStream >> rowCount >> colCount >> generation;

        for(int row = 0; row < rowCount; row++){
            for(int col = 0; col < colCount; col++){
                inStream >> map[row][col];
            }
        }
        for(int row = 0; row < rowCount; row++){
            for(int col = 0; col < colCount; col++){
                temp[row][col] = map[row][col];
            }
        }

        for(int j = 0; j < generation; j++)
            changeMap(rowCount, colCount);

        int count = 0;
        for(int row = 0; row < rowCount; row++){
            for(int col = 0; col < colCount; col++){
                if(map[row][col] == 'O') count++;
            }
        }
        cout << count << endl;
        for(int row = 0; row < rowCount; row++){
            for(int col = 0; col < colCount; col++){
                cout << map[row][col];
            }
            cout << endl;
        }
    }
    inStream.close();
}

bool isLiving(int rowCount, int colCount, int row, int col) {
    if (row < 0 || row > rowCount - 1 || col < 0 || col > colCount - 1 || map[row][col] != 'O') return false;
    else return true;
}

int livingCellCount(int rowCount, int colCount, int row, int col){
    int result = 0;
    for(int j = row - 1; j <= row + 1; j++){
        for(int k = col - 1; k <= col + 1; k++){
            if(j == row && k == col) continue;
            if(isLiving(rowCount, colCount, j, k)) result++;
        }
    }
    return result;
}

void changeMap(int rowCount, int colCount){
    for(int row = 0; row < rowCount; row++){
        for(int col = 0; col < colCount; col++){
            int count = livingCellCount(rowCount, colCount, row, col);
            if(count == 2 && map[row][col] == 'O') temp[row][col] = 'O';
            else if(count == 3) temp[row][col] = 'O';
            else temp[row][col] = 'X';
        }
    }
    for(int row = 0; row < rowCount; row++){
        for(int col = 0; col < colCount; col++){
            map[row][col] = temp[row][col];
        }
    }
}
