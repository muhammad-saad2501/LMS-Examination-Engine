#include "CourseRegistry.h"

int main()
{
    CourseRegistry registry;
    Course c1("CS201", "Object Oriented Programming", 3, "");
    Course c2("CS201L", "Object Oriented Programming Lab", 1, "CS201");
    Course c3("CS202", "Computer Organization and Assembly Language", 3, "");
    registry.addCourse(c1);
    registry.addCourse(c2);
    registry.addCourse(c3);
    Instructor i1("Mehak Saleem", 101);
    Instructor i2("Basit Sattar", 102);
    registry.assignInstructor("CS201", i1);
    registry.assignInstructor("CS201L", i1);
    registry.assignInstructor("CS202", i2);
    registry.displayAll();
    cout << "Total courses: " << registry.getCourseCount() << endl;
    cout << "Total credit hours: " << registry.getTotalCreditHours() << endl << endl;
    if (registry.canTakeCourse("CS201L", "CS201"))
        cout << "Student can take OOP Lab after OOP" << endl;
    else
        cout << "Student cannot take OOP Lab" << endl;
    if (registry.canTakeCourse("CS201L", "CS202"))
        cout << "Student can take OOP Lab after COAL" << endl;
    else
        cout << "Student cannot take OOP Lab after COAL" << endl;
    return 0;
}
