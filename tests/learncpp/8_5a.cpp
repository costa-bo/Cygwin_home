#include <iostream>
#include <cstdint>

class RGBA
{
private:
    std::uint8_t m_red;
    std::uint8_t m_green;
    std::uint8_t m_blue;
    std::uint8_t m_alpha;

public:
    RGBA(uint8_t red = 0, uint8_t green = 0, 
         uint8_t blue = 0, uint8_t alpha = 255) :
         m_red{red}, m_green{green}, m_blue{blue}, m_alpha{255}
    {
    }

    void print()
    {
        std::cout << "r=" << (int)m_red << " g=" << (int)m_green << " b=" << (int)m_blue << " a=" << (int)m_alpha << "\n";
    }
};

int main()
{
    RGBA teal(0, 127, 127);
    teal.print();
 
    return 0;
}
