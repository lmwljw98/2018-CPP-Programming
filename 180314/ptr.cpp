#include <iostream>

using namespace std;
int b(int);
int main(int argc, char const *argv[]) {
        const int k = 0;
        const int* v = &k;
        cout << *v << endl;
        int* test = new int;
        *test = 10;
        cout << *test << endl;
        int m = 123123;
        int &ref = m;
        cout << ++ref;
        cout << " " << m << endl;
        int var = 97;
        char* ptr = (char*)&var;
        cout << ptr << endl;
        int a = 071;
        cout << a << endl;
        cout <<b(3)<<endl;
        int x[5] = {0,1};
        for(int g =0;g<5;g++){
            cout<<x[g];
        }
        return 0;
}
int b(int c){
    return c;
}
