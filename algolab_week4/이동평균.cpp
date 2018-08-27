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
        int num; int sum; int move;
        int arr[256];
        int result[256];
        inStream >> num;
        for(int j = 0; j < num; j++)
            inStream >> arr[j];

        inStream >> move;
        int a = (num - move);
        int k = 0;
        while(k <= a){
            sum = 0;
            for(int j = k; j < move + k; j++){
                sum += arr[j];
            }
            sum /= move;
            result[k] = sum;
            k++;
        }
        cout << k << " ";
        for(int j = 0; j < k; j++){
            cout << result[j] << " ";
        }
        cout << endl;
    }
    inStream.close();
}
