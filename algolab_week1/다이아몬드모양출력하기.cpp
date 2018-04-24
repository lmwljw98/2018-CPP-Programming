#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
        int num = 0;
        int a = 0;

        ifstream inStream;
        inStream.open("input.txt");

        inStream >> num;

        for(int i = 0; i < num; i++) {
            inStream >> a;
            int con = a / 2;
                for (int j = 0; j < (a/2)+1; j++){
                    for(int k = 0; k < con; k++)
                        cout << "*";
                    for(int k = 0; k < 2*(j+1) - 1; k++)
                        cout << "+";
                    for(int k = 0; k < con; k++)
                        cout << "*";
                    cout << endl;
                    con--;
                }
                con += 2;
                for (int j = a/2; j > 0; j--){
                    for(int k = 0; k < con; k++)
                        cout << "*";
                    for(int k = 0; k < 2*j - 1; k++)
                        cout << "+";
                    for(int k = 0; k < con; k++)
                        cout << "*";
                    cout << endl;
                    con++;
                }
        }
        inStream.close();
}
