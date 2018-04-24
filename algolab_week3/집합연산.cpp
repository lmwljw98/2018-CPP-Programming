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
        unsigned int A[132] = {}; unsigned int B[132] = {}; unsigned int B_c[132] = {}; int temp;
        int intersec[132]; int union_[132]; int diff[132]; int i_idx = 0; int u_idx = 0; int d_idx = 0;
        int num;
        inStream >> num;
        for(int j = 0; j < num; j++){
            inStream >> temp;
            A[temp] = 1;
        }
        inStream >> num;
        for(int j = 0; j < num; j++){
            inStream >> temp;
            B[temp] = 1;
        }
        for(int j = 0; j < 132; j++){
            if(!B[j])
                B_c[j] = 1;
        }

        for(int k = 0; k < 132; k++){
            if(A[k] && B[k])
                intersec[i_idx++] = k;
        }
        for(int k = 0; k < 132; k++){
            if(A[k] || B[k])
                union_[u_idx++] = k;
        }
        for(int k = 0; k < 132; k++){
            if(A[k] && B_c[k])
                diff[d_idx++] = k;
        }

        cout << i_idx << " ";
        for(int n = 0; n < i_idx; n++)
            cout << intersec[n] << " ";
        cout << endl;

        cout << u_idx << " ";
        for(int n = 0; n < u_idx; n++)
            cout << union_[n] << " ";
        cout << endl;

        cout << d_idx << " ";
        for(int n = 0; n < d_idx; n++)
            cout << diff[n] << " ";
        cout << endl;
    }
    inStream.close();
}
