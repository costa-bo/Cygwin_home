#include <iostream>
#include <utility>

int main()
{
    const int length(9);
    int array[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };

    bool swaps = false;
    int j;
    for (j=1; j<length; j++){
        for (int i=0; i < length-j; i++){
            if (array[i] > array[i+1]){
                std::swap(array[i], array[i+1]);
                swaps = true;
            }
        }
        if (!swaps)
            break;
    }

    std::cout << "Swaps: " << j << std::endl;
    for (int i=0; i < length; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}
