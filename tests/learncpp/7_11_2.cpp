#include <iostream>

int sum(int x)
{
    if (x==0)
        return 0;
    else
        return x%10 + sum(x/10);
}

int main()
{
    int x;
    std::cin >> x;

    std::cout << "the sum of " << x << " is " << sum(x) << "\n";
}
