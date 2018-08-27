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
        int row; int col; int x;
        inStream >> row >> col >> x;
        int a[100][100];
        int b[100][100];
        for(int k = 0; k < row; k++){
            for(int j = 0; j < col; j++){
                inStream >> a[k][j];
            }
        }
        for(int k = 0; k < col; k++){
            for(int j = 0; j < x; j++){
                inStream >> b[k][j];
            }
        }
        for(int k = 0; k < row; k++){
            int temp = 1;
            while(temp <= x){
                int mul = 0;
                for(int j = 0; j < col; j++){
                    mul += (a[k][j] * b[j][temp-1]);
                }
                cout << mul << " ";
                temp++;
            }
            cout << endl;
        }
    }
    inStream.close();
}
