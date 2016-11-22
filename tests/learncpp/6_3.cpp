#include <iostream>

int main() 
{
    int array[] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    const int arrayLen = sizeof(array)/sizeof(array[0]);

    int userNum;
    do {
        std::cout << "Please give a number from 0-9: ";
        std::cin >> userNum;

        //if the user entered an invalid character  
        if (std::cin.fail()){
            std::cin.clear(); // reset any error flags
            std::cin.ignore(32767, '\n');
        }
    } while ((userNum < 1) || (userNum > 9));

    int matchIndex = -1;
    for (int i = 0; i < arrayLen; ++i){
        std::cout << array[i] << " ";
        if (userNum == array[i])
            matchIndex = i;
    }
            
    if (matchIndex != -1)
        std::cout << "\nYour number found at the array at position: "
                  << matchIndex + 1 << std::endl;
    else
        std::cout << "\nThe number wasn't found in the array\n";

}
