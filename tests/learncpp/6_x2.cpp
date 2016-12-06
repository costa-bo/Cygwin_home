#include <iostream>
#include <string>

struct Student{
    std::string name;
    int grade;
};

// although the same see 6.8chapter why the other is recomended.
//void sortArray(Student array[], int len)
void sortArray(Student *array, int len)
{
    for (int i=0; i < len; i++){
        for (int j=0; j < (len - 1) - i; j++){
            if (array[i].grade < array[i+1].grade){
                std::swap(array[i], array[i+1]);
            }
        }
    }
}

int main()
{
    int numOfStudents;
    do {
        std::cout << "How many students: ";
        std::cin >> numOfStudents;
    } while (numOfStudents <= 1);

    Student *studentsArray = new Student[numOfStudents];

    for (int i=0; i < numOfStudents; i++){
        std::cout << "Name of " << i+1 << " student: ";
        std::cin >> studentsArray[i].name;

        std::cout << "Grade of student " << studentsArray[i].name 
                  <<": ";
        std::cin >> studentsArray[i].grade;
    }

    sortArray(studentsArray, numOfStudents);

    for (int i=0; i<numOfStudents; i++){
        std::cout << studentsArray[i].name << " got "
                  << studentsArray[i].grade << std::endl;
    }

    delete[] studentsArray;
}
