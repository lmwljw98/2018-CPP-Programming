#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    int numTestCases = 0;
    ifstream inStream;
    inStream.open("input.txt");

    inStream >> numTestCases;

    typedef struct{
        int numGiven; int count;
    }info;

    for (int i = 0; i < numTestCases; i++){
        int num = 0;
        int num_of_max = 0;
        inStream >> num;
        info data[100] = {};
        int arr[100] = {};
        for (int j = 0; j < num; j++){
            inStream >> arr[j];
        }
        sort(arr, arr + num);
        data[0].numGiven = arr[0];
        data[0].count = 1;

        int a = 0;
        for(int k = 0; k < num - 1; k++){
            if(arr[k] != arr[k+1]){
                a++;
                data[a].numGiven = arr[k+1];
                data[a].count++;
            }
            else if(arr[k] == arr[k+1]){
                data[a].count++;
            }
        }

        int max_count = 0;
        for(int m = 0; m <= a; m++){
            max_count = max(data[m].count, max_count);
        }
        int f = 0;
        int result[100] = {};
        for(int n = 0; n <= a; n++){
            if(data[n].count == max_count){
                result[f] = data[n].numGiven;
                num_of_max++;
                f++;
            }
        }
        cout << num_of_max << " " << max_count << " ";
        for(int p = 0; p < f; p++){
            cout << result[p] << " ";
        }
        cout << endl;

    }
    inStream.close();
}
