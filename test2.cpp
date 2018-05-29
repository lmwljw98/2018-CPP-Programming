#include <iostream>

using namespace std;

int& IncreaseNum(int& a, int i)
{
    a += i;
    return a;
}

int main(){
    int a = 0;

    int num = IncreaseNum(a, 2);
    cout << num << endl;
    cout << a << endl;

    int &ref = IncreaseNum(a, 3);
    cout << ref << endl;
}
