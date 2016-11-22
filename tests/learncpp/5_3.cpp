#include <iostream>

int32_t calculate(int16_t x, int16_t y, char op)
{
    switch (op)
    {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        case '%':
            return x % y;
        default:
            std::cout << "Error" << std::endl;
    }
}
        

int main()
{
    std::cout << "2 ints and operator: " << std::endl;
    int a, b;
    char op;
    std::cin >> a;
    std::cin >> b;
    std::cin >> op;
    std::cout << "result: " << calculate(a, b, op) << std::endl;
}
