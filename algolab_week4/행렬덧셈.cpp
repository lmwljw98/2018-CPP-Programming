#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
    int numTestCases = 0;
    ifstream inStream;
    inStream.open("input.txt");

    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++){
        int row; int col;
        inStream >> row >> col;
        int a[100][100];
        int b[100][100];
        for(int k = 0; k < row; k++){
            for(int j = 0; j < col; j++){
                inStream >> a[k][j];
            }
        }
        for(int k = 0; k < row; k++){
            for(int j = 0; j < col; j++){
                inStream >> b[k][j];
            }
        }
        for(int k = 0; k < row; k++){
            for(int j = 0; j < col; j++){
                cout << a[k][j] + b[k][j]<< " ";
            }
            cout << endl;
        }
    }
    inStream.close();
}
