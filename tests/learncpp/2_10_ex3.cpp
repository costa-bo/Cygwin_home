#include <iostream>

int main()
{
    std::cout << "Entre 1st float: " << std::endl;
    double x;
    std::cin >> x;

    std::cout << "Entre 2st float: " << std::endl;
    double y;
    std::cin >> y;

    if (y == 0)
        return 0;
    else
        std::cout << "Entre operator(+,-,*,/): " << std::endl;
        char op;
        std::cin >> op;

    if (op == '+')
        std::cout << x+y << std::endl;
    if (op == '-')
        std::cout << x-y << std::endl;
    if (op == '*')
        std::cout << x*y << std::endl;
    if (op == '/')
        std::cout << x/y << std::endl;
    else
        return 0;
}
