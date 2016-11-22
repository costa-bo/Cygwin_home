#include <iostream>
#include <string>

namespace Animal{
    enum Animal{
        CHICKEN,
        DOG,
        CAT,
        ELEPHANT,
        DUCK,
        SNAKE,
        MAX_ANIMALS
    };
}

std::string print_Animal(Animal::Animal x)
{
    switch (x) {
        case Animal::CHICKEN:
            return "Chicken";
        case Animal::DOG:
            return "Dog";
        case Animal::CAT:
            return "Cat";
        case Animal::ELEPHANT:
            return "Elephant";
        case Animal::DUCK:
            return "Duck";
        case Animal::SNAKE:
            return "Snake";
        default:
            return "Animal not found!";
    }
}

void printNumOfLegs(const int arr_animal[])
{
    for (int i=0; i < Animal::MAX_ANIMALS; i++){
        std::cout << "The " << print_Animal(static_cast<Animal::Animal>(i)) << " has " 
                  << arr_animal[i] << " legs" << std::endl;
    }
}

int main()
{
    // First exercise
    double tempature[365] = {0.0};

    // Second exercise
    int arr_animal[Animal::MAX_ANIMALS] = {2, 4, 4, 4, 2};
    //std::cout << "An Elephant has " << arr_animal[Animal::ELEPHANT] << "legs\n";

    printNumOfLegs(arr_animal);
    
}
