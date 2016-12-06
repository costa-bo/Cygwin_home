#include <iostream>


//typedef int (*arithmeticFcn)(int, int);
using arithmeticFcn = int (*)(int, int);

struct arithmeticStruct{
    char op;
    arithmeticFcn f;
};

int getInteger()
{
    std::cout << "int : ";
    int x;
    std::cin >> x;

    return x;
}

char getOper()
{
    char op;
    do {
        std::cout << "Select operator(+, -, *, /): ";
        std::cin >> op;
    } while (op != '+' && op != '-' && op != '*' && op != '/');

    return op;
}

int add(int x, int y)
{
    return x+y;
}

int subtract(int x, int y)
{
    return x-y;
}

int multiply(int x, int y)
{
    return x*y;
}

int divide(int x, int y)
{
    return x/y;
}

static arithmeticStruct arithmeticArr[] {{'+', add}, {'-', subtract},
                                         {'*', multiply}, {'/', divide}};

arithmeticFcn getArithmeticFcn(char op)
{
    for (const auto &ide: arithmeticArr){
        if (ide.op == op){
            return ide.f;
            break;
        }
    }
}

int main()
{
    int x = getInteger();
    int y = getInteger();
    char op = getOper();

    arithmeticFcn f = getArithmeticFcn(op);
    std::cout << f(x, y) << std::endl;
    //std::cout << "resoult: " << culcutale(x, y, op) << std::endl;
}
