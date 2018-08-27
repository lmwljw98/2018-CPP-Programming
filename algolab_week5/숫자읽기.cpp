#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string convert(int num[]);
string one(int num);
string two(int num);

int main(){
    int numTestCases = 0;
    ifstream inStream;
    inStream.open("input.txt");

    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++){
        string num = ""; string input;
        inStream >> input;
        for(int j = 0; j < 10 - input.length(); j++){
            num += "0";
        }
        num = num + input;
        //cout << num << endl;

        int token1[1]; int token2[3]; int token3[3]; int token4[3];

        token1[0] = num[0] - '0';

        token2[0] = num[1] - '0';
        token2[1] = num[2] - '0';
        token2[2] = num[3] - '0';

        token3[0] = num[4] - '0';
        token3[1] = num[5] - '0';
        token3[2] = num[6] - '0';

        token4[0] = num[7] - '0';
        token4[1] = num[8] - '0';
        token4[2] = num[9] - '0';

        string result = "";
        one(token1[0]) == "none" ? result += "" : result += one(token1[0]) + "Billion_";
        convert(token2) == "none" ? result += "" : result += convert(token2) + "Million_";
        convert(token3) == "none" ? result += "" : result += convert(token3) + "Thousand_";
        convert(token4) == "none" ? result += "" : result += convert(token4);
        string last = result.substr(0, result.length()-1);

        cout << last << endl;
    }
    inStream.close();
}

string convert(int num[]){
    if(num[0] == 0 && num[1] == 0 && num[2] == 0){
        return "none";
    }
    string output = "";
    bool check = false;
    if(num[0] > 0){
        output += one(num[0]);
        output += "Hundred_";
    }
    if(num[1] > 0){
        if(num[1] == 1){
            if(num[2] == 0){ output += "Ten_"; }
            if(num[2] == 1){ output += "Eleven_"; }
            if(num[2] == 2){ output += "Twelve_"; }
            if(num[2] == 3){ output += "Thirteen_"; }
            if(num[2] == 4){ output += "Fourteen_"; }
            if(num[2] == 5){ output += "Fifteen_"; }
            if(num[2] == 6){ output += "Sixteen_"; }
            if(num[2] == 7){ output += "Seventeen_"; }
            if(num[2] == 8){ output += "Eighteen_"; }
            if(num[2] == 9){ output += "Nineteen_"; }
            check = true;
        }
        else{
            output += two(num[1]);
        }
    }
    if(num[2] > 0 && !check){
        output += one(num[2]);
    }
    return output;
}

string one(int num){
    if(num == 0) { return "none"; }
    if(num == 1) { return "One_"; }
    if(num == 2) { return "Two_"; }
    if(num == 3) { return "Three_"; }
    if(num == 4) { return "Four_"; }
    if(num == 5) { return "Five_"; }
    if(num == 6) { return "Six_"; }
    if(num == 7) { return "Seven_"; }
    if(num == 8) { return "Eight_"; }
    if(num == 9) { return "Nine_"; }
}

string two(int num){
    if(num == 2) { return "Twenty_"; }
    if(num == 3) { return "Thirty_"; }
    if(num == 4) { return "Forty_"; }
    if(num == 5) { return "Fifty_"; }
    if(num == 6) { return "Sixty_"; }
    if(num == 7) { return "Seventy_"; }
    if(num == 8) { return "Eighty_"; }
    if(num == 9) { return "Ninety_"; }
}
