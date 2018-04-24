#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
        int numTestCases = 0;
        ifstream inStream;
        inStream.open("input.txt");

        inStream >> numTestCases;

        for(int i = 0; i < numTestCases; i++) {
            int isClockwise;
            int xy_array[6] = {};
            int signedArea;
            for (int j = 0; j < 6; j++){
                inStream >> xy_array[j];
                //cout << xy_array[j] << " ";
            }
            //cout << endl;
            int a = (xy_array[2] - xy_array[0]) * (xy_array[5] - xy_array[1]);
            int b = (xy_array[4] - xy_array[0]) * (xy_array[3] - xy_array[1]);
            signedArea = ( a - b );
            if(signedArea < 0)
                isClockwise = -1;
            else if(signedArea > 0)
                isClockwise = 1;
            else
                isClockwise = 0;
            cout << abs(signedArea) << " " << isClockwise << endl;
        }
        inStream.close();
}
