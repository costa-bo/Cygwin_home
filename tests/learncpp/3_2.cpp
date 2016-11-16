#include <iostream>

bool isEven(int num)
{
    return (num % 2) == 0;
}

int main()
{
    std::cout << "Enter an int: " << std::endl;
    int x;
    std::cin >> x;

    if (isEven(x))
        std::cout << "It's even" << std::endl;
    else
        std::cout << "It's odd" << std::endl;

}
