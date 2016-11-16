#include <iostream>

int readNumber()
{
    std::cout << "please give a number: ";
    int x;
    std::cin >> x;
    return x;
}

void writeAnswer(int x)
{
    std::cout << "result: " << x << std::endl;
}

