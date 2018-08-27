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

    bool isPrime[10001];
    isPrime[1] = true; isPrime[2] = true; isPrime[3] = true;
    for(int k = 3; k < 10001; k++){
        for (int j = 2; j <= sqrt(k); j++){
            if(k % j == 0){
                isPrime[k] = false; break;
            }
            else{
                isPrime[k] = true;
            }
        }
    }

    for (int i = 0; i < numTestCases; i++){
        int num; int count; int of = 0;
        inStream >> num;
        int temp = num;

        for(int j = 2; j < 10001; j++){
            count = 0;
            if(isPrime[j]){
                while(temp % j == 0){
                    temp /= j; count++;
                }
                if(count > 0)
                    of++;
            }
        }
        cout << of << " ";

        for(int j = 2; j < 10001; j++){
            count = 0;
            if(isPrime[j]){
                while(num % j == 0){
                    num /= j; count++;
                }
                if(count > 0)
                    cout << j << " " << count << " ";
            }
        }
        cout << endl;
    }
    inStream.close();
}
