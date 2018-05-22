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
        int j; int m;
        int num1; int num2; int binary1[100] = {0}; int binary2[100] = {0};
        int weight1 = 0; int weight2 = 0;
        int temp1; int temp2;
        int distance = 0;

        inStream >> num1 >> num2;
        temp1 = num1;
        temp2 = num2;

        for(j = 0; temp1 > 0; j++){
            binary1[j] = temp1 % 2;
            temp1 /= 2;
        }
        for(m = 0; temp2 > 0; m++){
            binary2[m] = temp2 % 2;
            temp2 /= 2;
        }

        for(int k = 0; k < j; k++){
            if(binary1[k] == 1)
                weight1++;
        }
        for(int k = 0; k < m; k++){
            if(binary2[k] == 1)
                weight2++;
        }

        int len = max(j, m);
        for(int a = 0; a < len; a++){
            if(binary1[a] != binary2[a]){
                distance++;
            }
        }

        cout << weight1 << " " << weight2 << " " << distance << endl;

    }
    inStream.close();
}
