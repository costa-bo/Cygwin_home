#include <iostream>

int sumTo(int value)
{
    int sum(0);
    for (int i=1; i <=value; i++)
        sum += i;
    return sum;
}

int main()
{
    for (int i=0; i < 20; i+=2)
        std::cout << i << std::endl;


    std::cout << "\nGive me..." << std::endl;
    int x;
    std::cin >> x;
    std::cout << "Sum: " << sumTo(x) << std::endl;
}
