#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
        int num = 0;
        int a = 0, b = 0, sum;

        ifstream inStream;
        inStream.open("input.txt");
        if(inStream.fail()) {
                cerr << "Input file opening failed.";
                exit(1);
        }

        inStream >> num;

        for(int i = 0; i < num; i++) {
                sum = 0;
                inStream >> a >> b;
                while(a <= b) {
                        sum += a;
                        a++;
                }
                cout << sum << endl;
        }
        inStream.close();
}
