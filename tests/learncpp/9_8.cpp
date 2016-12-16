#include <iostream>
#include <vector>
#include <string>

struct StudentGrade{
    std::string name;
    char grade;
};

class GradeMap
{
private:
    std::vector<StudentGrade> m_map;

public:
    GradeMap()
    {
    }

    char& operator[](const std::string name)
    {
        for (auto &iname: m_map){
            if (name == iname.name)
                return iname.grade;
        }
        StudentGrade newStudent;
        newStudent.name = name;

        m_map.push_back(newStudent);

        return m_map.back().grade;
    }
};
int main()
{
    GradeMap grades;
    grades["Joe"] = 'A';
    grades["Frank"] = 'B';
    std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
    std::cout << "Frank has a grade of " << grades["Frank"] << '\n';
 
    return 0;
}

/* dangling reference

int main()
{
    GradeMap grades;
    char& gradeJoe = grades["Joe"];
    gradeJoe = 'A'; 
    char& gradeFrank = grades["Frank"];
    gradeFrank = 'B';
    std::cout << "Joe has a grade of " << gradeJoe << '\n';
    std::cout << "Frank has a grade of " << gradeFrank << '\n';
 
    return 0;
}
*/
