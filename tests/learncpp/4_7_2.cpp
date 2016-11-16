#include <iostream>

struct Fraction{
    int16_t nominator;
    int16_t denominator;
};

void multiply(Fraction x, Fraction y)
{
    double total = static_cast<double>(x.nominator * y.nominator) /
                            (x.denominator * y.denominator);

    std::cout << "multiply: " << total << "\n";
}

int main()
{
    Fraction fr1;
    Fraction fr2;

    std::cout << "1st fraction nominator: \n";
    std::cin >> fr1.nominator;

    std::cout << "1st fraction denominator: \n";
    std::cin >> fr1.denominator;

    std::cout << "2st fraction nominator: \n";
    std::cin >> fr2.nominator;

    std::cout << "2st fraction denominator: \n";
    std::cin >> fr2.denominator;

    multiply(fr1, fr2);
}
