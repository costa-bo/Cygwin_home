#include <iostream>
#include <cassert>

class Stack
{
private:
    int array[9];
    int stackLength;

public:
    void reset()
    {
        stackLength = 0;

        for (int i; i<=9; i++){
            array[i] = 0;
        }
    }

    bool push(int x)
    {
        if (stackLength == 9)
            return false;

        array[stackLength] = x;
        stackLength++;
        return true;
    }

    int pop()
    {
        assert(stackLength > 0 && "The stack length is 0");

        array[stackLength] = 0;
        stackLength--;
    }

    void print()
    {
        std::cout << "( ";
        for (int i=0; i < stackLength; i++){
            std::cout << array[i] << " ";
        }
        std::cout << ")" << std::endl;
    }
};

int main()
{
    Stack stack;
    stack.reset();
 
    stack.print();
 
    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();
 
    stack.pop();
    stack.print();
 
    stack.pop();
    stack.pop();
 
    stack.print();
 
    return 0;
}
