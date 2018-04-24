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
        int num, sum = 0, a = 0;
        inStream >> num;
        for (int j = 1; j*j <= num; j++){
            if(num % j == 0){
                sum += j; a++;
                if(j != num / j){
                    sum += num / j; a++;
                }
            }
        }
        cout << a-1 << " " << sum - num << endl;
    }
}
