#include <iostream>
 
int main()
{
    int scores[] = { 84, 92, 76, 81, 56 };
    const int numStudents = sizeof(scores) / sizeof(scores[0]);
 
    int maxIndex = 0; // keep track of our largest score
    for (int student = 0; student < numStudents; ++student)
        if (scores[student] > scores[maxIndex])
            maxIndex = student;
 
    std::cout << "The best index was " << maxIndex + 1 << '\n';
 
    return 0;
}
