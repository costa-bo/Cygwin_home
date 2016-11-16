#include <iostream>

#include "constants.h"

void curent_height(double height, int seconds)
{
    double dist_fallen = (myConstants::gravity * seconds * seconds)/2;
    height = height - dist_fallen;

    if (height <= 0)
        std::cout << "At " << seconds << " seconds, the ball is on the ground" 
                  << std::endl;
    else
        std::cout << "At " << seconds << " seconds, the ball is at height: " 
                  << height << " meters" << std::endl;

}


int main()
{
    std::cout << "Give tower height: " << std::endl;
    double height;
    std::cin >> height;

    curent_height(height, 0);
    curent_height(height, 1);
    curent_height(height, 2);
    curent_height(height, 3);
    curent_height(height, 4);
    curent_height(height, 5); 
}
