#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
        int numTestCases = 0;
        ifstream inStream;
        inStream.open("input.txt");

        inStream >> numTestCases;

        int dp[1351][5+1];
        dp[1][0] = 1;
        for(int j = 1; j < 1350; j++) {
                int mini = 2147483647;
                dp[j][2] = dp[j][0] * 2;
                dp[j][3] = dp[j][0] * 3;
                dp[j][5] = dp[j][0] * 5;

                for(int a = 1; a <= j; a++) {
                        if(dp[a][0] > dp[j][0]) {
                                mini = min(mini, dp[a][0]);
                        }
                        else if(dp[a][2] > dp[j][0]) {
                                mini = min(mini, dp[a][2]);
                        }
                        else if(dp[a][3] > dp[j][0]) {
                                mini = min(mini, dp[a][3]);
                        }
                        else if(dp[a][5] > dp[j][0]) {
                                mini = min(mini, dp[a][5]);
                        }
                }

                dp[j+1][0] = mini;
        }

        for (int i = 0; i < numTestCases; i++) {
                int num;
                inStream >> num;


                cout << dp[num][0] << endl;
        }
        inStream.close();
}
