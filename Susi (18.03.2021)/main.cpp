#include "student.hpp"
#include "susi.hpp"
using namespace std;


int main()
{
    const char *STUDENTSFILE = "students.txt";
    const char *SUBJECTSFILE = "subjects.txt";
    char *name = "maya", *lastname ="ivanova";
    int fn = 123;
    Student maya(name, lastname, fn);
    std::cout << maya.fileName << endl;

    ofstream fout(SUBJECTSFILE);
    fout << "OOP" << endl;
    fout << "Algebra" << endl;
    fout << "Geometry" << endl;
    fout.close();

    Susi system(SUBJECTSFILE, STUDENTSFILE);
    system.addStudent(maya);
    system.addSubjectToStudent(123, "OOP");
    system.printInfo(123);
    system.save();


    return 0;
}
