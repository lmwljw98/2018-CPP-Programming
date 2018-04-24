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
            //int con = a / 2;
                for (int j = a-1; j >= 0; j--){
                    for(int k = 0; k < a; k++){
                            if(k == a/2 && j == a/2){
                                cout << "O";
                            }
                            else if(k == a/2){
                                cout << "I";
                            }
                            else if(k == j){
                                cout << "*";
                            }
                            else if(j == a/2){
                                cout << "+";
                            }
                            else{
                                cout << ".";
                            }
                    }
                    cout << endl;
                }
        }
        inStream.close();
}
