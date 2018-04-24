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
        int j; int num; int binary[32]; int count = 0; int temp;
        inStream >> num;
        temp = num;

        for(j = 0; temp > 0; j++){
            binary[j] = temp % 2;
            temp /= 2;
        }

        for(int k = 0; k < j; k++){
            if(binary[k] == 1)
                count++;
        }

        if(count % 2 == 0)
            cout << num << endl;
        else
            cout << num + 2147483648 << endl;
    }
    inStream.close();
}
