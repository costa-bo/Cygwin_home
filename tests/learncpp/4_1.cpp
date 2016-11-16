#include <iostream>

int main()
{
    using namespace std;

    cout << "give an int: " << endl;
    int8_t x;
    cin >> x;

    cout << "give a larger int: " << endl;
    int8_t y;
    cin >> y;

    if (y < x) {
        cout << "Swapping the values" << endl;
        int8_t tmp(x);
        x = y;
        y = tmp;
    }
    cout << "Smaller: " << x << endl;
    cout << "larger: " << y << endl;

}
