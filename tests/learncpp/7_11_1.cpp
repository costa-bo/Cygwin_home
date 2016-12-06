#include <iostream>

int factorial(int x)
{
    if (x == 0)
        return 1;
    else
        return x * factorial(x-1);
}

int main()
{
    for (int i; i<=7; ++i)
        std::cout << i << ": " << factorial(i) << "\n";
}
