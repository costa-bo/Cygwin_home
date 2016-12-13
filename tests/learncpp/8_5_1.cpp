#include <iostream>
#include <string>

class Ball
{
private:
    std::string m_color;
    double m_radious;

public:
    Ball(const std::string color){ 
        m_color = color; 
        m_radious = 10.0;
    }

    Ball(double radious){ 
        m_color = "Black"; 
        m_radious = radious; 
    }

    Ball(const std::string color, double radious){
        m_color = color;
        m_radious = radious;
    }

    Ball(){ 
        m_color = "Black"; 
        m_radious = 10.0;
    }

    void print()
    {
        std::cout << "color: " << m_color << ", radious: " << m_radious << std::endl;
    }
};

int main()
{
        Ball def;
        def.print();
 
    Ball blue("blue");
    blue.print();
    
    Ball twenty(20.0);
    twenty.print();
    
    Ball blueTwenty("blue", 20.0);
    blueTwenty.print();
 
    return 0;
}
