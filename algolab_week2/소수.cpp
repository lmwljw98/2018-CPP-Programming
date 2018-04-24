#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
    int numTestCases = 0;
    ifstream inStream;
    inStream.open("input.txt");

    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++){
        int num;
        bool isPrime = true;
        inStream >> num;
        for (int j = 2; j <= sqrt(num); j++){
            if(num % j == 0){
                cout << "0" << endl;
                isPrime = false; break;
            }
        }
        if(isPrime)
            cout << "1" << endl;
    }
    inStream.close();
}
