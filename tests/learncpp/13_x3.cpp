#include <iostream>
#include <string>

template<class T1, class T2>
class Pair
{
private:
    T1 m_x;
    T2 m_y;

public:
    Pair(const T1 &x, const T2 &y) : m_x(x), m_y(y)
    {
    }

    T1& first() { return m_x; }
    const T1& first() const  { return m_x; }
    T2& second() { return m_y; }
    const T2& second() const { return m_y; }
};

template<class T>
class StringValuePair : public Pair<std::string, T>
{
public:
    StringValuePair(const std::string &str, const T &value) : 
        Pair<std::string, T>(str, value)
    {
    }
}; 

int main()
{
    StringValuePair<int> svp("Hello", 5);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
 
    return 0;
}
