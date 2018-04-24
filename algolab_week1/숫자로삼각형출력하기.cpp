#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
        int num = 0;
        int a = 0;

        ifstream inStream;
        inStream.open("input.txt");
        if(inStream.fail()) {
                cerr << "Input file opening failed.";
                exit(1);
        }

        inStream >> num;

        for(int i = 0; i < num; i++) {
                inStream >> a;

                for (int j = 1; j < a+1; j++){
                    cout << j << ' ';
                    int b = 1;
                    int sum = 0;
                    for(int m = 0; m < j-1; m++){
                        sum += (a - b);
                        cout << j + sum << ' ';
                        b++;
                    }
                    cout << endl;
                }

        }
        inStream.close();
}
