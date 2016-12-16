#include <iostream>
#include <cmath>
#include <cstdint> // for fixed width integers

class FixedPoint2
{
private:
    int16_t m_nonFra;
    int8_t m_fraction;

public:
    FixedPoint2(int16_t nonFra=0, int8_t fra=0): m_nonFra(nonFra), m_fraction(fra)
    {
    }

    FixedPoint2(double value)
    {
        m_nonFra = static_cast<int16_t>(value);
        
        m_fraction = static_cast<std::int8_t>(round((value - m_nonFra) * 100));
    }

    friend std::ostream& operator<< (std::ostream &out, FixedPoint2 &fp);
    friend std::istream& operator>> (std::istream &in, FixedPoint2 &fp);

    friend bool operator== (FixedPoint2 &fp1, FixedPoint2 &fp2);

    FixedPoint2 operator- (FixedPoint2 &fp);
    friend FixedPoint2 operator+(FixedPoint2 &fp1, FixedPoint2 &fp2);

    operator double()
    {
        return m_nonFra + static_cast<double>(m_fraction) / 100;
    }
    
};

FixedPoint2 operator+(FixedPoint2 &fp1, FixedPoint2 &fp2)
{
    // If the sum of the decimals is >=100, we need to adjust base up by 1 and decimal down by 100
    // If the sum of the decimals is <=-100, we need to adjust base down by 1 and decimal up by 100
    // We could use an if statement to do this (and that would be fine).  Here's an alternate solution using integer arithmetic.

    // First, determine which way our base needs to move (if at all)
    int overflow  = (fp1.m_nonFra + fp2.m_fraction) / 100;
 
    // Second, adjust our base and decimals accordingly
    return FixedPoint2(fp1.m_nonFra + fp2.m_nonFra + overflow, fp1.m_fraction + fp2.m_fraction - overflow * 100);
}

FixedPoint2 FixedPoint2::operator- (FixedPoint2 &fp)
{
    return FixedPoint2(-fp.m_nonFra, -fp.m_fraction);
}

std::istream& operator>> (std::istream &in, FixedPoint2 &fp)
{
    double d;
    in >> d;
    fp = FixedPoint2(d);

    return in;
}

std::ostream& operator<< (std::ostream &out, FixedPoint2 &fp)
{
    out << fp.m_nonFra << '.';
 
    // If our decimal is a single digit, we need to pad with a 0
    if (fp.m_fraction < 10 && fp.m_fraction > - 10)
        out << '0';

    // Because some compilers typedef std::int8_t as a char, we need to cast it to an int to ensure it prints as an integer
    out << static_cast<int>(fp.m_fraction > 0 ? fp.m_fraction : -fp.m_fraction);

    return out;
}

bool operator== (FixedPoint2 &fp1, FixedPoint2 &fp2)
{
    return (fp1.m_nonFra == fp2.m_nonFra && fp1.m_fraction == fp2.m_fraction);
}

void testAddition()
{
    // h/t to reader Sharjeel Safdar for this function
    std::cout << std::boolalpha;
    std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
    std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
    std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
    std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
    std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
    std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
    std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
    std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow
}
 
int main()
{
    testAddition();
 
    FixedPoint2 a(34, 56); 
    std::cout << a << '\n';
 
    std::cout << -a << '\n';
 
    std::cout << "Enter a number: "; // enter 5.678
    std::cin >> a;
    
    std::cout << "You entered: " << a << '\n';
 
    return 0;
}

