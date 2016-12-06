#include <iostream>

void printString(const char *string)
{
    while (*string != '\0'){
        std::cout << *string;
        string ++;
    }
        
    std::cout << "\n";
}

int main()
{
    printString("Hello World!");
}
