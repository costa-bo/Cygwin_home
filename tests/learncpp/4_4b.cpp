#include <string>
#include <iostream>
 
int main()
{
    std::cout << "Enter your full name: ";
    std::string name;
    std::getline(std::cin, name);
 
    std::cout << "Now enter your age: ";
    int age;
    std::cin >> age;
 
    double yel = static_cast<double>(age) / name.length();

    std::cout << "You've lived " << yel << " years for each letter in you name" << std::endl;
 
    return 0;
}
