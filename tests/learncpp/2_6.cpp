#include <iostream>

bool isPrime(int x)
{
    if ( x == 2 || x == 3 || x == 5 || x == 7 )
        return true;
    else
        return false;
}

int main()
{
    std::cout << "Entre a positive num: " << std::endl;
    int x;
    std::cin >> x;

    if (isPrime(x))
        std::cout << "The digit is prime" << std::endl;
    else 
        std::cout << "The digit is not prime" << std::endl;

}
