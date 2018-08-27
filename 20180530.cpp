//20171676 이정우

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
    map<string, int> dic;
    vector<string> vec;

    ifstream in;
    in.open("data");

    string data;
    in >> data;
    for(int i = 0; i < data.length(); i += 10){
        string token = data.substr(i, 10);
        vec.push_back(token);
        if ( dic.find(token) == dic.end() ) {
          // not found
          dic[token] = 1;
        }
        else {
          // found
          dic[token] += 1;
        }
    }
    vector<string>::iterator it;
    int temp = 0;
    string result;
    for(it = vec.begin(); it != vec.end(); it++){
        if(dic[*it] > temp){
            temp = dic[*it];
            result = *it;
        }
    }
    cout << result << " " << temp << endl;
}
