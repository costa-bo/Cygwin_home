#include <iostream>

void swapInts(int &refx, int &refy)
{
    int z = refx;
    refx=refy;
    refy = z;
}

int main()
{
    int a(1);
    int b(2);

    swapInts(a, b);

    std::cout << a << ", " << b << std::endl;
}
