#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
        srand( (unsigned)time( NULL ) );
        for(int i = 0; i < 1000; i++)
                cout << rand() % 201 + -100 << endl;
        return 0;
}
