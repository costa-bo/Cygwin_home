#include <iostream>
#include <vector>

class Shape
{
public:
    friend std::ostream& operator<< (std::ostream& out, const Shape& shape)
    {
        return shape.print(out);
    }

    virtual std::ostream& print(std::ostream& out) const = 0;

    virtual ~Shape()
    {
    }
};

class Point
{
private:
    int m_x;
    int m_y;
    int m_z;

public:
    Point(int x, int y, int z): m_x(x), m_y(y), m_z(z)
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Point &p)
    {
        out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
        return out;
    }
};

class Triangle : public Shape
{
private:
    Point m_p1;
    Point m_p2;
    Point m_p3;

public:
    Triangle(Point p1, Point p2, Point p3): m_p1(p1), m_p2(p2), m_p3(p3)
    {
    }

    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Triangle(" << m_p1 << m_p2 << m_p3 << ")";
        return out;
    }
};

class Circle : public Shape
{
private:
    Point m_x;
    int radius;

public:
    Circle(Point x, int r): m_x(x), radius(r)
    {
    }

    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Circle(" << m_x << ", radius " << radius << ")";
        return out;
    }

    int getRadius() { return radius; }
};

int getLargestRadius(std::vector<Shape*> &v)
{
    int max = 0;
    for (int i=0; i < v.size()-1; i++){
        Circle* cir = dynamic_cast<Circle*>(v[i]);
        if (!cir){
            continue;
        } else {
            if (cir->getRadius() > max){
                max = cir->getRadius();
            }
        }
    }
    return max;
}

int main()
{
    std::vector<Shape*> v;
    v.push_back(new Circle(Point(1, 2, 3), 7));
    v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
    v.push_back(new Circle(Point(4, 5, 6), 3));
 
    // print each shape in vector v on its own line here
    for (int i; i < v.size(); i++){
        std::cout << *v[i] << std::endl;
    }
 
        std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function
 
    // delete each element in the vector here
    for (int i=0; i < v.size(); i++){
        delete v[i];
    }
}
