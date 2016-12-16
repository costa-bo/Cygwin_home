#include <iostream>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int numerator = 0, int denominator = 1) :
             m_numerator(numerator), m_denominator(denominator)
    {
        // We put reduce() in the constructor to ensure any fractions we make get reduced!
        // Since all of the overloaded operators create new Fractions, we can guarantee this will get called here
        reduce();
    }

    void print()
    {
        std::cout << m_numerator << "/" << m_denominator << "\n";
    }

    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, const int nValue);
    friend Fraction operator*(const int nValue, const Fraction &f1);

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void reduce()
    {
        int m_gcd = gcd(m_numerator, m_denominator);
        m_numerator /= m_gcd;
        m_denominator /= m_gcd;
    }
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    int numerator = f1.m_numerator * f2.m_numerator;
    int denominator = f1.m_denominator * f2.m_denominator;

    return Fraction(numerator, denominator);
}

Fraction operator*(const Fraction &f1, const int nValue)
{
    int numerator = f1.m_numerator * nValue;

    return Fraction(numerator, f1.m_denominator);
}

Fraction operator*(const int nValue, const Fraction &f1)
{
    return f1 * nValue;
}
 
int main()
{
    Fraction f1(2, 5);
    f1.print();
 
    Fraction f2(3, 8);
    f2.print();
 
    Fraction f3 = f1 * f2;
    f3.print();
 
    Fraction f4 = f1 * 2;
    f4.print();
 
    Fraction f5 = 2 * f2;
    f5.print();
 
    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();
}
