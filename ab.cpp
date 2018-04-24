#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int check(int a, int b);

int main(){
        int num = 0;
        int a = 0, b = 0;

        ifstream inStream;
        inStream.open("input.txt");
        if(inStream.fail()) {
                cerr << "Input file opening failed.";
                exit(1);
        }

        inStream >> num;

        for(int i = 0; i < num; i++) {
                inStream >> a >> b;
                cout << a + b << " " << a - b << " " << (abs)(a - b) << " " << a * b << " " << a / b << " " << a % b << " " << max(a, b) << " " << check(a, b) << endl;
        }
}

int check(int a, int b){
        if(a == b)
                return 1;
        else
                return 0;
}
