#include <iostream>
 
// Loop between 1 and 5
int main()
{
    int outer = 1;
    while (outer <= 5)
    {
        int inner = 5;
        while (inner > 0){
            if (inner - outer > 0)
                std::cout << "  ";
            else
                std::cout << inner << " ";
            inner--;
        }
 
        // print a newline at the end of each row
        std::cout << "\n";
        ++outer;
    }
 
    return 0;
}

