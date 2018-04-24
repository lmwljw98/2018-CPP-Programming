#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

int main(){
    int numTestCases = 0;
    ifstream inStream;
    inStream.open("input.txt");

    inStream >> numTestCases;

    typedef struct{
        string data; bool s_check;
    }info;

    for (int i = 0; i < numTestCases; i++){
        info number[10000];
        for (int j = 0; j < 10000; j++){
            stringstream ss; ss << j;
            string str = ss.str();
            if(j < 10)
                str = "000" + str;
            else if(j < 100)
                str = "00" + str;
            else if(j < 1000)
                str = "0" + str;
            number[j].data = str;
            number[j].s_check = true;
        }
        int result[10000]; int result_index;
        for (int t = 0; t < 10000; t++) {
            result[t] = t;
        }

        int a; inStream >> a;
        string given; int strike; int ball;
        int strike_count; int ball_count; int answer_count; string temp1; string temp2;
        for (int k = 0; k < a; k++){
            inStream >> given >> strike >> ball;
            answer_count = 0;
            for(int m = 0; m < 10000; m++){
                strike_count = 0; ball_count = 0;
                if(number[m].s_check){
                    temp1 = number[m].data; temp2 = given;
                    for(int n = 0; n < 4; n++){
                        if(number[m].data[n] == given[n]){
                            number[m].data[n] = 'c';
                            given[n] = 'c';
                            strike_count++;
                        }
                    }
                    for(int n = 0; n < 4; n++){
                        for(int v = 0; v < 4; v++){
                            if(given[v] == 'c'){ continue; }
                            if(number[m].data[n] == given[v]){
                                number[m].data[n] = 'c';
                                given[v] = 'c';
                                ball_count++;
                            }
                        }
                    }
                    if(strike_count == strike && ball_count == ball){
                        number[m].s_check = true;
                        result_index = m;
                        answer_count++;
                    }
                    else{
                        number[m].s_check = false;
                    }
                    number[m].data = temp1; given = temp2;
                }
            }
        }
        if(answer_count == 0) { cout << "-2" << endl; }
        else if(answer_count > 1) { cout << "-1" << endl; }
        else { cout << result[result_index] << endl; }
    }
    inStream.close();
}
