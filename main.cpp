// main.cpp
#include "MyString.h"
using namespace std;

int main()
{
    MyString s1("C++");
    MyString s2("Programming");
    MyString s3;
    s3 = s1 + s2;
    cout << s3 << endl;
    for (int i=0; i<3; i++) cout << s3[i] << " ";
    s3[0] = '1';
    cout << endl << s3 << endl;
}
