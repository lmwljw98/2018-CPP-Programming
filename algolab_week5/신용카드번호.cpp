#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
    int numTestCases = 0;
    ifstream inStream;
    inStream.open("input.txt");

    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++){
        string card;
        int sum = 0;
        inStream >> card;
        int cnt = 2;
        for(int j = card.length() - 2; j >= 0; j--){
            if(cnt % 2 == 0){
                sum += (card[j] - '0') * 2;
                if((card[j] - '0') * 2 >= 10){
                    sum -= 9;
                }
            }
            else{
                sum += card[j] - '0';
            }
            cnt++;
        }
        int first = card[0] - '0';
        int checksum = card[card.length() - 1] - '0';
        //cout << sum << endl;
        //cout << checksum << endl;
        bool isRight = false;
        if(first == 3){
            if(card.length() == 14 || card.length() == 15){
                if( (sum + checksum) % 10 == 0 ){
                    cout << 1 << endl;
                    isRight = true;
                }
            }
        }
        else if(first == 6 || first == 5){
            if(card.length() == 16){
                if( (sum + checksum) % 10 == 0 ){
                    cout << 1 << endl;
                    isRight = true;
                }
            }
        }
        else if(first == 4){
            if(card.length() == 13 || card.length() == 16){
                if( (sum + checksum) % 10 == 0 ){
                    cout << 1 << endl;
                    isRight = true;
                }
            }
        }
        if(!isRight)
            cout << 0 << endl;
    }
    inStream.close();
}
