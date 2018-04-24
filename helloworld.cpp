#include<iostream>

int mode;
namespace Graphics{
        int mode;
}
namespace Graphics{
        int y;
}

int main()
{
        mode = 1;
        Graphics::mode = 2;

        using namespace Graphics;

        mode = 11;
        ::mode = 12;
        Graphics::mode = 13;
        y = 14;
}
