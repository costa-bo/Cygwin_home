#include <iostream>
 
// Loop between 1 and 5
int main()
{
    int outer = 5;
    while (outer >= 0)
    {
        // loop between 1 and outer
        int inner = outer;
        while (inner > 0)
            std::cout << inner-- << " ";
 
        // print a newline at the end of each row
        std::cout << "\n";
        --outer;
    }
 
    return 0;
}
