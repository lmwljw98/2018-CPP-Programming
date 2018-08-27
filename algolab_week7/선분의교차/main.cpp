#include <iostream>
#include "MyLineSegment.h"
#include <fstream>

using namespace std;

int main(){
    int numTestCases = 0;
    ifstream inStream;
    inStream.open("input.txt");

    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++){
        int x, y, w, z, a, b, c, d;
        inStream >> x >> y >> w >> z >> a >> b >> c >> d;
        MyPoint p1(x, y);
        MyPoint p2(w, z);
        MyPoint p3(a, b);
        MyPoint p4(c, d);

        MyLineSegment line1(p1, p2);
        MyLineSegment line2(p3, p4);

        if(line1.properIntersection(line2)){
            cout << 1 << endl;
        }
        else if(line1.improperIntersection(line2)){
            cout << 2 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    inStream.close();
}
