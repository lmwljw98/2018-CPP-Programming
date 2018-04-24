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
        int num, a, zero_count = 0, count2 = 0, count5 = 0, mul = 1;
        inStream >> num;
        for (int j = 0; j < num; j++){
            inStream >> a;
            while (a % 2 == 0){
                a /= 2;
                count2++;
            }
            while (a % 5 == 0){
                a /= 5;
                count5++;
            }
            a %= 10;
            mul *= a;
            mul %= 10;
        }

        while(count2 > 0 && count5 > 0){
            count2--;
            count5--;
            zero_count++;
        }
        while(count2--){
            mul *= 2;
            mul %= 10;
        }
        while(count5--){
            mul *= 5;
            mul %= 10;
        }
        cout << mul << " " << zero_count << endl;
    }
    inStream.close();
}
