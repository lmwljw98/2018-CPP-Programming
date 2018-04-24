#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
        int num = 0;
        int b = 0, k;

        ifstream inStream;
        inStream.open("input.txt");

        inStream >> num;

        for(int i = 0; i < num; i++) {
            int sum = 1;
            inStream >> k;
                for(int a = 0; a < k; a++){
                    inStream >> b;
                    sum *= b % 10;
                    sum %= 10;
                }
                cout << sum % 10 << endl;
        }
        inStream.close();
}
