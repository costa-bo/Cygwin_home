#include <iostream>
#include <string>

int main()
{
    const std::string array[] = {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

    std::cout << "Give a name: ";
    std::string name;
    std::cin >> name;

    for (const auto &arname : array){
        if (name == arname){
            std::cout << "the Name found\n";
            return 0;
        }
    }

    std::cout << "The name did not found\n";
}
        
    
