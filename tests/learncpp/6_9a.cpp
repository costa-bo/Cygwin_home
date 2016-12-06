#include <iostream>
#include <algorithm>
#include <string>

void sortNames(std::string *array, int len)
{
    for (int i=0; i < len; ++i){
        for (int j=0; j < (len-1) - i; j++){
            if (array[j] > array[j+1]){
                std::swap(array[j], array[j+1]);
            }
        }
    }
}
                

int main()
{
    std::cout << "Number of names you with to entre: \n";
    int numberOfNames;
    std::cin >> numberOfNames;

    std::string *cptrNames = new std::string[numberOfNames];

    for (int i=0; i < numberOfNames; ++i){
        std::cout << "Entre " << i+1 << " name: ";
        std::cin >> cptrNames[i];
    }

    sortNames(cptrNames, numberOfNames);

    for (int i=0; i<numberOfNames; i++)
        std::cout << cptrNames[i] << std::endl;

    delete[] cptrNames;
    cptrNames = nullptr;
}
