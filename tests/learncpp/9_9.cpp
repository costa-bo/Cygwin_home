#include <iostream>
#include <string>

class Mystring
{
private:
    std::string m_string;

public:
    Mystring(std::string string) : m_string(string)
    {
    }

    std::string operator()(int a, int b)
    {
        std::string temp{""};
        for (int i=0; i < b; i++){
            temp += m_string[a++];
        }
        return temp;
    }
};

int main()
{
    Mystring string("Hello, world!");
    std::cout << string(7, 5); // start at index 7 and return 5 characters
 
    return 0;
}
