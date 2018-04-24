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
        int xy[6] = {};
        double a, b, c, m, n, o;
        for (int j = 0; j < 6; j++)
            inStream >> xy[j];
        m = pow(xy[0] - xy[2], 2) + pow(xy[1] - xy[3], 2);
        n = pow(xy[0] - xy[4], 2) + pow(xy[1] - xy[5], 2);
        o = pow(xy[2] - xy[4], 2) + pow(xy[3] - xy[5], 2);
        c = max(max(m, n), o);
        if(c == m){
            a = n; b = o;
        }
        else if(c == n){
            a = m; b = o;
        }
        else{
            a = m; b = n;
        }

        if(sqrt(c) >= sqrt(a)+sqrt(b)){
            cout << "0" << endl;
        }
        else{
            if(a + b == c){
                cout << "1" << endl;
            }
            else if(a + b < c){
                cout << "2" << endl;
            }
            else if(a + b > c){
                cout << "3" << endl;
            }
        }
    }
    inStream.close();
}
