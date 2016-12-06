#include <iostream>

int bin(int x)
{
    if (x!=0)
        bin(x/2);

    std::cout << x%2;
//    if (x%2)
//        std::cout << "1";
//    else 
//        std::cout << "0";
}

int main()
{
    int x;
    std::cin >> x;

    bin(x);
    std::cout << "\n";
}
