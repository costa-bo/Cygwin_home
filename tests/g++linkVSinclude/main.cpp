#include <iostream>

/*  I can compile either with the command:
        g++ main.cpp
    but including the following line:
        #include "add.cpp"

    or with the command:
        g++ main.cpp add.cpp
    but with the following line:
        int add(int x, int y);
*/

//#include "add.hpp"

int add(int x, int y);

int main()
{
    std::cout << add(3, 4) << std::endl;
    return 0; 
}
