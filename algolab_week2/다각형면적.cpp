#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
    int numTestCases = 0;
    ifstream inStream;
    inStream.open("input.txt");

    inStream >> numTestCases;

    typedef struct{
        int x; int y;
    }offset;

    for (int i = 0; i < numTestCases; i++){
        int num, sum = 0, clockwise;
        inStream >> num;
        offset a[num];
        for(int j = 0; j < num; j++){
            inStream >> a[j].x >> a[j].y;
        }
        for(int k = 0; k <= num-1; k++){
            if(k == num - 1){
                k = 0;
                sum += ( (a[k].x * a[k+1].y) - (a[k].y * a[k+1].x) );
                break;
            }
            sum += ( (a[k].x * a[k+1].y) - (a[k].y * a[k+1].x) );
        }
        if(sum > 0){
            clockwise = 1;
        }
        else if(sum < 0){
            clockwise = -1;
        }
        cout << abs(sum) << " " << clockwise << endl;
    }
    inStream.close();
}
