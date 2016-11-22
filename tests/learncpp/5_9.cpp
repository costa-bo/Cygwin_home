#include <iostream>
#include <cstdlib> // for srand() and rand()
#include <ctime> // for time()

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    for (int i=0; i < 100; i++){
        std::cout << rand() << "\t";

    if ((i + 1) % 5 == 0)
        std::cout << "\n";
    }
}
