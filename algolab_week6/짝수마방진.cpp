#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int map[50][50] = {0};
int reverse_map[50][50] = {0};
int result_map[50][50] = {0};

void magicSquare4k(int);
void magicSquareNot4k(int);
void L(int, int, int);
void U(int, int, int);
void X(int, int, int);

int main(){
    int numTestCases = 0;
    ifstream inStream;
    inStream.open("input.txt");

    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++){
        int size;
        inStream >> size;

        if(size % 4 == 0) magicSquare4k(size);
        else magicSquareNot4k(size);

        for(int row = 0; row < size; row++){
            for(int col = 0; col < size; col++){
                cout << result_map[row][col] << " ";
            }
            cout << endl;
        }
    }
    inStream.close();
}

void magicSquare4k(int size){
    int num = 1;
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            map[row][col] = num;
            num++;
        }
    }
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            num--;
            reverse_map[row][col] = num;
        }
    }

    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            if((row + 1) % 4 < 2 && (col + 1) % 4 >= 2)
                result_map[row][col] = map[row][col];
            else if((row + 1) % 4 >= 2 && (col + 1) % 4 < 2)
                result_map[row][col] = map[row][col];
            else
                result_map[row][col] = reverse_map[row][col];
        }
    }
}

void magicSquareNot4k(int size){
    int divided = size / 2;
    int odd[100][100] = {0};
    int row = 0;
    int col = divided / 2;
    int k = (size - 2) / 4;

    for(int num = 1; num <= divided * divided; num++){
        odd[row][col] = num;
        if(num % divided == 0) { row++; }
        else { row--; col++; }
        if(row < 0) { row = divided - 1; }
        if(col > divided - 1) { col = 0; }
    }

    for(int m = 0; m < divided; m++){
        for(int n = 0; n < divided; n++){
            if(m < k+1){
                if(m == k && n == k) { U(odd[m][n], m, n); }
                else { L(odd[m][n], m, n); }
            }
            else if(m == k+1){
                if(n == k) { L(odd[m][n], m, n); }
                else { U(odd[m][n], m, n); }
            }
            else { X(odd[m][n], m, n); }
        }
    }
}

void L(int num, int row, int col){
    int _row, _col;
    if(row > 0) _row = row * 2;
    else _row = row;
    if(col > 0) _col = col * 2;
    else _col = col;

    int last_num = num * 4;
    result_map[_row][_col+1] = last_num - 3;
    result_map[_row+1][_col] = last_num - 2;
    result_map[_row+1][_col+1] = last_num - 1;
    result_map[_row][_col] = last_num;
}

void U(int num, int row, int col){
    int _row, _col;
    if(row > 0) _row = row * 2;
    else _row = row;
    if(col > 0) _col = col * 2;
    else _col = col;

    int last_num = num * 4;
    result_map[_row][_col] = last_num - 3;
    result_map[_row+1][_col] = last_num - 2;
    result_map[_row+1][_col+1] = last_num - 1;
    result_map[_row][_col+1] = last_num;
}

void X(int num, int row, int col){
    int _row, _col;
    if(row > 0) _row = row * 2;
    else _row = row;
    if(col > 0) _col = col * 2;
    else _col = col;

    int last_num = num * 4;
    result_map[_row][_col] = last_num - 3;
    result_map[_row+1][_col+1] = last_num - 2;
    result_map[_row+1][_col] = last_num - 1;
    result_map[_row][_col+1] = last_num;
}
