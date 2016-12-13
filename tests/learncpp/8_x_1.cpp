#include <iostream>
#include <cmath>

class Point2d
{
private:
    double m_x, m_y;

public:
    Point2d(int x = 0.0, int y = 0.0): m_x(x), m_y(y)
    {
    }

    void print()
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }

    friend double distanceFrom(const Point2d &a, const Point2d &b);
};

double distanceFrom(const Point2d &a, const Point2d &b)
{
    return sqrt((a.m_x - b.m_x)*(a.m_x - b.m_x) + (a.m_y - b.m_y)*(a.m_y - b.m_y));
}

int main()
{
    Point2d first;
    Point2d second(3.0, 4.0);
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
 
    return 0;
}
