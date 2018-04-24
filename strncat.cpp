#include <iostream>
using namespace std;

void ncat(char* s1, const char* s2, const int n);
int len(const char* n);
int main(){
    char s1[20] = "enen";
    char s2[20] = "World! Hi Hi";
    char s3[20] = "asdf";

    //ncat(s1, s2, 5);
    ncat(s1, s2, 10);
    cout << s1;
}

int len(const char* n){
    int i = 0;
    while(n[i] != '\0')
        i++;
    return i;
}

void ncat(char* s1, const char* s2, const int n){
    int k = len(s1);
    for(int i = 0; i < n; i++){
        if(s2[i] == '\0')
            break;
        s1[k + i] = s2[i];
    }
}
