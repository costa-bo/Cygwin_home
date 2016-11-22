#include <iostream>
#include <utility>

int main()
{
    int array[] = { 30, 60, 20, 50, 40, 10 };
    int arraySize = sizeof(array)/ sizeof(array[0]);

    int bigestIndex;

    for (int startIndex = 0; startIndex < arraySize; startIndex++){
        bigestIndex = startIndex;
        for (int curentIndex = startIndex + 1; curentIndex < arraySize; curentIndex++){
            if (array[curentIndex] > array[bigestIndex])
                bigestIndex = curentIndex;
        }
        std::swap(array[startIndex], array[bigestIndex]);
    }

    for (int i=0; i < arraySize; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";

}
