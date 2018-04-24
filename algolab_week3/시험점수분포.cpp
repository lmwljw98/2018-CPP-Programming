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
        int num; int score[101]; int temp;
        for(int n = 0; n < 101; n++){
            score[n] = -1;
        }
        inStream >> num;
        for(int j = 0; j < num; j++){
            inStream >> temp;
            score[temp]++;
        }
        for(int k = 0; k < 101; k++){
            if(score[k] > -1){
                cout << k << " " << score[k] + 1 << " ";
            }
        }
        cout << endl;

    }
    inStream.close();
}
