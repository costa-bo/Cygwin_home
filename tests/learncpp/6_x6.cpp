#include <iostream>
#include <array>

enum Rank{
    ACE,
    R2,
    R3,
    R4,
    R5,
    R6,
    R7,
    R8,
    R9,
    R10,
    JACK,
    QUEEN,
    KING,
    MAX_RANKS
};

enum Suit{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
    MAX_SUITS
};

struct Card{
    Rank rank;
    Suit suit;
};

void printCard(const Card &c)
{
    switch (c.rank){
        case ACE: std::cout << "A"; break;
        case R2: std::cout << "2"; break;
        case R3: std::cout << "3"; break;
        case R4: std::cout << "4"; break;
        case R5: std::cout << "5"; break;
        case R6: std::cout << "6"; break;
        case R7: std::cout << "7"; break;
        case R8: std::cout << "8"; break;
        case R9: std::cout << "9"; break;
        case R10: std::cout << "10"; break;
        case JACK: std::cout << "J"; break;
        case QUEEN: std::cout << "Q"; break;
        case KING: std::cout << "K"; break;
    }

    switch (c.suit){
        case CLUBS: std::cout << "C"; break;
        case DIAMONDS: std::cout << "D"; break;
        case HEARTS: std::cout << "H"; break;
        case SPADES: std::cout << "S"; break;
    }

}

void printDeck(const std::array<Card, 52> &deck)
{
    for (const auto &c: deck){
        printCard(c);
        std::cout << " ";
    }
    std::cout << "\n";
}

void swapCard(Card &a, Card &b)
{
    Card temp = a;
    a = b;
    b = temp;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    // evenly distribute the random number across our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(std::array<Card, 52> &d)
{
    for (int i=0; i < 52; i++){ 
        swapCard(d.at(i), d.at(getRandomNumber(0, 51)));
    }
}

int getCardValue(const Card &c)
{
    if (c.rank == ACE)
        return 11;
    else if (c.rank >= R10)
        return 10;
    else
        return static_cast<int>(c.rank)+1;
}

bool playblackjack(const std::array<Card, 52> &deck)
{
    const Card *cardptr = &deck[0];
    int dealerScore = getCardValue(*cardptr);
    std::cout << "Dealer: " << dealerScore << std::endl;

    int playerScore = getCardValue(*(cardptr + 1)) + getCardValue(*(cardptr + 2));
    std::cout << "You: " << playerScore << std::endl;

    cardptr = &deck[3];
    bool isPlayerWon;
    do {
        std::cout << "Do you want to hit or stand? [h/s]: " << std::endl;
        char hit;
        std::cin >> hit;
        if (hit == 'h'){
            playerScore += getCardValue(*cardptr);
            cardptr++;
            std::cout << "Your score now is: " << playerScore << std::endl;
            if (playerScore > 21){
                std::cout << "You busted!\n";
                isPlayerWon = false;
                return isPlayerWon;
            }
        } else if (hit == 's'){
            while (dealerScore < 17){
                dealerScore += getCardValue(*(cardptr++));
                cardptr++;
                std::cout << "Dealer's score: " << dealerScore << std::endl;
            }
            if (dealerScore > 21){
                std::cout << "Dealer busted!\n";
                return isPlayerWon=true;
            } else if (dealerScore < playerScore){
                return isPlayerWon=true;
            } else
                return isPlayerWon=false;
        }
    } while (true);
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    std::array<Card, 52> deck;

    int card(0);
    for (int i=0; i < MAX_SUITS; i++){
        for (int j=0; j < MAX_RANKS; j++){
            deck.at(card).suit = static_cast<Suit>(i);
            deck.at(card).rank = static_cast<Rank>(j);
            ++card;
        }
    }

    printDeck(deck);
    shuffleDeck(deck);
    printDeck(deck);

    if (playblackjack(deck))
        std::cout << "You won\n";
    else
        std::cout << "Sorry, you lost!\n";
}
