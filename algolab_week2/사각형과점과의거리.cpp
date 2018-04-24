#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int pow(int a);

int main(){
        int numTestCases = 0;
        ifstream inStream;
        inStream.open("input.txt");

        inStream >> numTestCases;

        for(int i = 0; i < numTestCases; i++) {
            int rectangle[4] = {};
            int point[2] = {};
            int a, b;
            int temp[2] = {};
            for (int j = 0; j < 4; j++)
                inStream >> rectangle[j];
            for (int m = 0; m < 2; m++)
                inStream >> point[m];
            if(point[0] >= min(rectangle[0], rectangle[2]) && point[0] <= max(rectangle[0], rectangle[2]) && point[1] >= min(rectangle[1], rectangle[3]) && point[1] <= max(rectangle[1], rectangle[3])){
                a = 0; b = 0;
                cout << a << " " << b << endl;
                continue;
            }
            else if(point[0] < min(rectangle[0], rectangle[2]) && point[1] < min(rectangle[1], rectangle[3])){
                temp[0] = rectangle[0];
                temp[1] = rectangle[1];
            }
            else if(point[0] > max(rectangle[0], rectangle[2]) && point[1] > max(rectangle[1], rectangle[3])){
                temp[0] = rectangle[2];
                temp[1] = rectangle[3];
            }
            else if(point[0] < min(rectangle[0], rectangle[2]) && point[1] > max(rectangle[1], rectangle[3])){
                temp[0] = rectangle[0];
                temp[1] = rectangle[3];
            }
            else if(point[0] > max(rectangle[0], rectangle[2]) && point[1] < min(rectangle[1], rectangle[3])){
                temp[0] = rectangle[2];
                temp[1] = rectangle[1];
            }
            else if(!(point[0] >= min(rectangle[0], rectangle[2]) && point[0] <= max(rectangle[0], rectangle[2])) && point[1] >= min(rectangle[1], rectangle[3]) && point[1] <= max(rectangle[1], rectangle[3])){
                if(point[0] > max(rectangle[0], rectangle[2])){
                    temp[0] = abs(point[0] - min(abs(point[0] - rectangle[0]), abs(point[0] - rectangle[2])));
                    temp[1] = point[1];
                }
                else{
                    temp[0] = abs(point[0] + min(abs(point[0] - rectangle[0]), abs(point[0] - rectangle[2])));
                    temp[1] = point[1];
                }
            }
            else if((point[0] >= min(rectangle[0], rectangle[2]) && point[0] <= max(rectangle[0], rectangle[2])) && !(point[1] >= min(rectangle[1], rectangle[3]) && point[1] <= max(rectangle[1], rectangle[3]))){
                if(point[1] > max(rectangle[1], rectangle[3])){
                    temp[1] = abs(point[1] - min(abs(point[1] - rectangle[1]), abs(point[1] - rectangle[3])));
                    temp[0] = point[0];
                }
                else{
                    temp[1] = abs(point[1] + min(abs(point[1] - rectangle[1]), abs(point[1] - rectangle[3])));
                    temp[0] = point[0];
                }
            }
            a = pow(point[0] - temp[0]) + pow(point[1] - temp[1]);
            b = abs(point[0] - temp[0]) + abs(point[1] - temp[1]);
            cout << a << " " << b << endl;
        }
        inStream.close();
}

int pow(int a){
    return a * a;
}
