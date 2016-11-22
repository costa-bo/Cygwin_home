#include <iostream>

int main()
{
    char iii('a');
    while (iii < 'z'){
        std::cout << iii << ":" << static_cast<int>(iii) << " ";

        iii++;
    }
    std::cout << "\n";
}
