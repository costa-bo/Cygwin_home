#include <iostream>
#include <cstdlib>
#include <ctime>

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int getGuess(int numTry)
{
    int guess;
    std::cout << "Guess #" << numTry << ":" << std::endl;
    std:: cin >> guess;
    return guess;
}

bool playAgain()
{
    char pl;

    do {
        std::cout << "Would you like to play again (y/n)?" << std:: endl;
        std::cin >> pl;

        switch (pl){
            case ('y'):
                return true;
            case ('n'):
                return false;
        }
    } while (true);
}
        

int main()
{
    srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock

    std::cout << "Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is." << std::endl;
    int randNum;

    int numTry = 0;
    int guess;
    do{
        randNum = getRandomNumber(1, 100);
        do{
            numTry++;
            guess = getGuess(numTry);

            if (guess < randNum)
                std::cout << "Your guess is too low." << std::endl;
            else if (guess > randNum)
                std::cout << "Your guess is too high." << std::endl;
            else {
                std::cout << "Correct! You win!" << std::endl;
                break;
            }
        } while (numTry <7);

        if (numTry == 7)
            std::cout << "Sorry, you lose.  The correct number was " << randNum << std::endl;

        numTry = 0; 

    } while (playAgain());
}
