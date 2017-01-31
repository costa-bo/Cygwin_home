#include <iostream>

template<typename T>
class Pair1
{
private:
    T m_p1;
    T m_p2;

public:
    Pair1(const T &p1, const T &p2) : m_p1(p1), m_p2(p2)
    {
    }

    T& first() { return m_p1; }
    const T& first() const { return m_p1; }
    T& second() { return m_p2; }
    const T& second() const { return m_p2; }
};

int main()
{
    Pair1<int> p1(5, 8);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
 
    const Pair1<double> p2(2.3, 4.5);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
 
    return 0;
}
