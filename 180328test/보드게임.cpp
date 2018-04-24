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
        int Anum, Bnum;
        in >> Anum;
        in >> Bnum;
        cout << max(2 * (Anum / 16) + (Anum % 16), 2 * (Bnum / 16) + (Bnum % 16)) << endl;
    }
    in.close();
}
