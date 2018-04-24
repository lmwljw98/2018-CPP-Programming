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
        int a[4], b[4];
        inStream >> a[0] >> a[1] >> a[2] >> a[3];
        inStream >> b[0] >> b[1] >> b[2] >> b[3];
        if(a[0] == a[2]){
            if(b[1] <= max(a[1], a[3]) && b[1] >= min(a[1], a[3]) && a[0] >= min(b[0], b[2]) && a[0] <= max(b[0], b[2])){
                if(a[0] == b[0] || a[0] == b[2]){
                    cout << "2" << endl;
                }
                else if(a[1] == b[1] || a[3] == b[1]){
                    cout << "2" << endl;
                }
                else{
                    cout << "1" << endl;
                }
            }
            else{
                cout << "0" << endl;
            }
        }
        else if(b[0] == b[2]){
            if(a[1] <= max(b[1], b[3]) && a[1] >= min(b[1], b[3]) && b[0] >= min(a[0], a[2]) && b[0] <= max(a[0], a[2])){
                if(b[0] == a[0] || b[0] == a[2]){
                    cout << "2" << endl;
                }
                else if(b[1] == a[1] || b[3] == a[1]){
                    cout << "2" << endl;
                }
                else{
                    cout << "1" << endl;
                }
            }
            else{
                cout << "0" << endl;
            }
        }
        else{
            cout << "0" << endl;
        }
    }
}
