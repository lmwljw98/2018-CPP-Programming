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
        in >> a;
        in >> b;
        in >> c;
        if(c >= a+b){
            cout << "0" << endl;
        }
        else{
            if(a == b && b == c){
                cout << "1" << endl;
            }
            else if(a*a + b*b == c*c){
                cout << "2" << endl;
            }
            else if((a == b && a != c) || (b == c && a != b) || (a == c && a != b)){
                cout << "3" << endl;
            }
            else{
                cout << "4" << endl;
            }
        }
    }
    in.close();
}
