#include <iostream>
#include <cassert>

class IntArray
{
private:
    int *m_array = nullptr;
    int m_len;

public:
    IntArray(int len=0)
    {
        assert(len>0 && "out of len");
        m_array = new int[len];
        m_len = len;
    }

    ~IntArray()
    {
        delete[] m_array;
    }

    friend std::ostream& operator<< (std::ostream &out, IntArray &ar);
    int& operator[] (const int index);
    IntArray& operator= (IntArray &arr);

};

std::ostream& operator<< (std::ostream &out, IntArray &ar)
{
    assert(ar.m_len);

    for (int i=0; i < ar.m_len; i++){
        out << ar.m_array[i];
    }
    return out;
}

int& IntArray::operator[] (const int index)
{
    return m_array[index];
}

IntArray& IntArray::operator= (IntArray &arr)
{
    if (this == &arr)
        return *this;
    
    m_len = arr.m_len;

    //delete[] m_array;

    for (int i=0; i<arr.m_len; i++){
        m_array[i] = arr.m_array[i];
    }

    return *this; //to ksexasa
}


IntArray fillArray()
{
    IntArray a(5);
    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;
 
    return a;
}
 
int main()
{
    IntArray a = fillArray();
    std::cout << a << '\n';
 
    IntArray b(1);
    a = a;
    b = a;
 
    std::cout << b << '\n';
 
    return 0;
}
