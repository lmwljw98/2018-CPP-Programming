#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string convert(string data);

int main(){
    int numTestCases = 0;
    ifstream inStream;
    inStream.open("input.txt");

    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++){
        string input;
        string result = "";
        string data = "";
        inStream >> input;
        for(int j = 0; j < input.length(); j++){
            if(input[j] == '|'){
                result += convert(data);
                data = "";
                continue;
            }
            if(input[j] == '#'){
                result += convert(data);
                result += "_";
                data = "";
                continue;
            }
            data += input[j];
        }
        result += convert(data);
        cout << result << endl;
    }
    inStream.close();
}

string convert(string data){
    if(data == ".-")
        return "A";
    else if(data == "-...")
        return "B";
    else if(data == "-.-.")
        return "C";
    else if(data == "-..")
        return "D";
    else if(data == ".")
        return "E";
    else if(data == "..-.")
        return "F";
    else if(data == "--.")
        return "G";
    else if(data == "....")
        return "H";
    else if(data == "..")
        return "I";
    else if(data == ".---")
        return "J";
    else if(data == "-.-")
        return "K";
    else if(data == ".-..")
        return "L";
    else if(data == "--")
        return "M";
    else if(data == "-.")
        return "N";
    else if(data == "---")
        return "O";
    else if(data == ".--.")
        return "P";
    else if(data == "--.-")
        return "Q";
    else if(data == ".-.")
        return "R";
    else if(data == "...")
        return "S";
    else if(data == "-")
        return "T";
    else if(data == "..-")
        return "U";
    else if(data == "...-")
        return "V";
    else if(data == ".--")
        return "W";
    else if(data == "-..-")
        return "X";
    else if(data == "-.--")
        return "Y";
    else if(data == "--..")
        return "Z";
}
