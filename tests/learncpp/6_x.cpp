#include <iostream>

enum Item{
    POTION,
    TORCH,
    ARROWS,
    MAX_ITEMS
};

int countTotalItems(const int *array)
{
    int totalItems = 0;
    for (int i=0; i<MAX_ITEMS; i++)
        totalItems += array[i];

    return totalItems;
}

int main()
{
    int numOfItems[] {2, 5, 10};

    int totalItems = countTotalItems(numOfItems);

    std::cout << "Total items: " << totalItems << std::endl;
}
