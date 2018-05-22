#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int check(string word, char map[][101], int rowCount, int colCount);
int main(){
    int numTestCases = 0;
    ifstream inStream;
    inStream.open("input.txt");

    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++){
        int rowCount, colCount;
        string one_row;
        inStream >> rowCount >> colCount;

        char map[101][101] = {0};

        for(int row = 0; row < rowCount; row++){
            inStream >> one_row;
            for(int col = 0; col < colCount; col++){
                map[row][col] = one_row[col];
            }
        }

        int inputnum;
        inStream >> inputnum;
        string* words = new string[inputnum];
        for(int j = 0; j < inputnum; j++){
            inStream >> words[j];
        }
        for(int j = 0; j < inputnum; j++){
            cout << check(words[j], map, rowCount, colCount) << endl;
        }
        delete[] words;
    }
    inStream.close();
}

int check(string word, char map[][101], int rowCount, int colCount){
    int result = -1;
    for(int row = 0; row < rowCount; row++){
        for(int col = 0; col < colCount; col++){
            if(map[row][col] == word[0]){
                bool isTrue = false;
                int my_len = word.length() - 1;

                if(row - my_len > -1){
                    for(int a = 1; a < word.length(); a++){
                        if(word[a] != map[row-a][col]) { isTrue = false; break; }
                        else { isTrue = true; }
                    }
                    if(isTrue) { cout << row + 1 << " " << col + 1 << " "; return 0; }
                }

                if(row - my_len > -1 && col + my_len < colCount + 1){
                    for(int a = 1; a < word.length(); a++){
                        if(word[a] != map[row-a][col+a]) { isTrue = false; break; }
                        else { isTrue = true; }
                    }
                    if(isTrue) { cout << row + 1 << " " << col + 1 << " "; return 1; }
                }

                if(col + my_len < colCount + 1){
                    for(int a = 1; a < word.length(); a++){
                        if(word[a] != map[row][col+a]) { isTrue = false; break; }
                        else { isTrue = true; }
                    }
                    if(isTrue) { cout << row + 1 << " " << col + 1 << " "; return 2; }
                }

                if(row + my_len < rowCount + 1 && col + my_len < colCount + 1){
                    for(int a = 1; a < word.length(); a++){
                        if(word[a] != map[row+a][col+a]) { isTrue = false; break; }
                        else { isTrue = true; }
                    }
                    if(isTrue) { cout << row + 1 << " " << col + 1 << " "; return 3; }
                }

                if(row + my_len < rowCount + 1){
                    for(int a = 1; a < word.length(); a++){
                        if(word[a] != map[row+a][col]) { isTrue = false; break; }
                        else { isTrue = true; }
                    }
                    if(isTrue) { cout << row + 1 << " " << col + 1 << " "; return 4; }
                }

                if(row + my_len < rowCount + 1 && col - my_len > -1){
                    for(int a = 1; a < word.length(); a++){
                        if(word[a] != map[row+a][col-a]) { isTrue = false; break; }
                        else { isTrue = true; }
                    }
                    if(isTrue) { cout << row + 1 << " " << col + 1 << " "; return 5; }
                }

                if(col - my_len > -1){
                    for(int a = 1; a < word.length(); a++){
                        if(word[a] != map[row][col-a]) { isTrue = false; break; }
                        else { isTrue = true; }
                    }
                    if(isTrue) { cout << row + 1 << " " << col + 1 << " "; return 6; }
                }

                if(row - my_len > -1 && col - my_len > -1){
                    for(int a = 1; a < word.length(); a++){
                        if(word[a] != map[row-a][col-a]) { isTrue = false; break; }
                        else { isTrue = true; }
                    }
                    if(isTrue) { cout << row + 1 << " " << col + 1 << " "; return 7; }
                }
            }
        }
    }
    return -1;
}
