#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

void bit26(int [], int);
void bit32(int [], int, int []);
int bin2dec(int [], bool);
int main(){
    int numTestCases = 0;
    ifstream inStream;
    inStream.open("input.txt");

    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++){
        bool state; int num; int binary[33] = {0}; int temp; int new_binary[27] = {0};
        inStream >> state >> num;
        temp = num;
        if(!state){
            bit26(binary, temp);
            cout << bin2dec(binary, state) << endl;
        }
        else{
            bit32(binary, temp, new_binary);
            cout << bin2dec(new_binary, state) << endl;
        }

    }
    inStream.close();
}

int bin2dec(int binary[], bool state){
    int sum = 0; int m;
    if(!state) { m = 32; }
    else { m = 27; }
    for(int j = 1; j < m; j++){
        if(binary[j] == 1)
            sum += pow(2, (double)(j - 1));
    }
    return sum;
}

void bit26(int binary[], int temp){
    int j; int pcount = 0;
    for(j = 1; temp > 0; j++){
        if(j == 1 || j == 2 || j == 4 || j == 8 || j == 16){
            binary[j] = 9;
            continue;
        }
        binary[j] = temp % 2;
        temp /= 2;
    }
    for(j = 1; j < 32; j += 2){
        if(binary[j] == 1)
            pcount++;
    }
    pcount % 2 == 0 ? binary[1] = 0 : binary[1] = 1;
    pcount = 0;

    for(j = 2; j < 32; j += 4){
        for(int k = 0; k < 2; k++){
            if(binary[j+k] == 1)
                pcount++;
        }
    }
    pcount % 2 == 0 ? binary[2] = 0 : binary[2] = 1;
    pcount = 0;

    for(j = 4; j < 32; j += 8){
        for(int k = 0; k < 4; k++){
            if(binary[j+k] == 1)
                pcount++;
        }
    }
    pcount % 2 == 0 ? binary[4] = 0 : binary[4] = 1;
    pcount = 0;

    for(j = 8; j < 32; j += 16){
        for(int k = 0; k < 8; k++){
            if(binary[j+k] == 1)
                pcount++;
        }
    }
    pcount % 2 == 0 ? binary[8] = 0 : binary[8] = 1;
    pcount = 0;

    for(j = 16; j < 32; j += 16){
        for(int k = 0; k < 16; k++){
            if(binary[j+k] == 1)
                pcount++;
        }
    }
    pcount % 2 == 0 ? binary[16] = 0 : binary[16] = 1;
    pcount = 0;
}

void bit32(int binary[], int temp, int new_binary[]){
    int j; int pcount = 0; int error_point = 0;
    for(j = 1; temp > 0; j++){
        binary[j] = temp % 2;
        temp /= 2;
    }

    for(j = 1; j < 32; j += 2){
        if(binary[j] == 1)
            pcount++;
    }
    pcount % 2 == 0 ? : error_point += 1;
    pcount = 0;

    for(j = 2; j < 32; j += 4){
        for(int k = 0; k < 2; k++){
            if(binary[j+k] == 1)
                pcount++;
        }
    }
    pcount % 2 == 0 ? : error_point += 2;
    pcount = 0;

    for(j = 4; j < 32; j += 8){
        for(int k = 0; k < 4; k++){
            if(binary[j+k] == 1)
                pcount++;
        }
    }
    pcount % 2 == 0 ? : error_point += 4;
    pcount = 0;

    for(j = 8; j < 32; j += 16){
        for(int k = 0; k < 8; k++){
            if(binary[j+k] == 1)
                pcount++;
        }
    }
    pcount % 2 == 0 ? : error_point += 8;
    pcount = 0;

    for(j = 16; j < 32; j += 16){
        for(int k = 0; k < 16; k++){
            if(binary[j+k] == 1)
                pcount++;
        }
    }
    pcount % 2 == 0 ? : error_point += 16;
    pcount = 0;

    binary[error_point] = !binary[error_point];
    binary[1] = 9; binary[2] = 9; binary[4] = 9; binary[8] = 9; binary[16] = 9;

    int k = 1;
    for(int j = 1; j < 32; j++){
        if(binary[j] != 9){
            new_binary[k] = binary[j];
            k++;
        }
    }
}
