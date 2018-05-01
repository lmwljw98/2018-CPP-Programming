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
        int year; int month; int day;
        int result = 0;
        int end_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        inStream >> year >> month >> day;
        
        for(int j = 1; j < year; j++){
            if( ((j % 4 == 0) && (j % 100 != 0)) || (j % 400 == 0) ){
                result += 366;
            }
            else{
                result += 365;
            }
        }

        for(int j = 0; j < month-1; j++){
            if(j == 1){
                if( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) ){
                    result += (end_of_month[j] + 1);
                }
                else{
                    result += end_of_month[j];
                }
            }
            else{
                result += end_of_month[j];
            }
        }

        result += day;

        cout << result % 7 << endl;
    }
    inStream.close();
}
