#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
    ifstream in;
    int numTestCases;

    in.open("input.txt");
    in >> numTestCases;

    for (int i = 0; i < numTestCases; i++){
        int a = 0, b = 0, c = 0;
        int fin = 0;
        in >> a;
        in >> b;
        for (int k = 0; k < a; k++){
            in >> c;
            if(b == c){
                fin++;
            }
        }
        cout << fin << endl;
    }
}
