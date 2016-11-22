#include <iostream>
#include <string>

enum class Animal {
    ANIMAL_PIG,
    ANIMAL_CHICKEN,
    ANIMAL_GOAT,
    ANIMAL_CAT,
    ANIMAL_DOG,
    ANIMAL_OSTRICH
};

std::string getAnimalName(Animal an)
{
    switch (an)
    {
        case Animal::ANIMAL_PIG:
            return "Pig";
        case Animal::ANIMAL_CHICKEN:
            return "Chiken";
        case Animal::ANIMAL_GOAT:
            return "Goat";
        case Animal::ANIMAL_CAT:
            return "Cat";
        case Animal::ANIMAL_DOG:
            return "Dog";
        case Animal::ANIMAL_OSTRICH:
            return "Ostrich";
        default :
            return "Animal not found";
    }
}

void printNumberOfLegs(Animal an)
{
    std::cout << getAnimalName(Animal::ANIMAL_CAT) << " has ";

    switch (an)
    {
        case Animal::ANIMAL_CHICKEN:
        case Animal::ANIMAL_OSTRICH:
            std::cout << "2";
            break;
        case Animal::ANIMAL_PIG:
        case Animal::ANIMAL_GOAT:
        case Animal::ANIMAL_CAT:
        case Animal::ANIMAL_DOG:
            std::cout << "4";
            break;
        default :
            std::cout << "Animal not found";
    }

    std::cout << " legs" << std::endl;
}

int main()
{
    printNumberOfLegs(Animal::ANIMAL_CAT);
    printNumberOfLegs(Animal::ANIMAL_CHICKEN);
}
