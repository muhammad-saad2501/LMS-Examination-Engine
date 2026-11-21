#include "Course.h"

class CourseRegistry
{
    private:
    Course courses[20];
    int courseCount;
    int findCourseIndex(string code)
    {
        for (int i = 0; i < courseCount; i++)
        {
            if (courses[i].getCode() == code)
                return i;
        }
        return -1;
    }
    public:
    CourseRegistry()
    {
        courseCount = 0;
    }
    bool addCourse(Course c)
    {
        if (courseCount >= 20)
        {
            cout << "Registry is full!" << endl;
            return false;
        }
        if (findCourseIndex(c.getCode()) != -1)
        {
            cout << "Course " << c.getCode() << " already exists!" << endl;
            return false;
        }
        if (c.hasPrerequisite() && findCourseIndex(c.getPrerequisiteCode()) == -1)
        {
            cout << "Cannot add " << c.getCode() << ": prerequisite "
                 << c.getPrerequisiteCode() << " does not exist!" << endl;
            return false;
        }
        courses[courseCount] = c;
        courseCount++;
        return true;
    }
    bool assignInstructor(string code, Instructor i)
    {
        int index = findCourseIndex(code);
        if (index == -1)
        {
            cout << "Course " << code << " not found!" << endl;
            return false;
        }
        courses[index].assignInstructor(i);
        return true;
    }
    bool canTakeCourse(string courseCode, string completedCode)
    {
        int index = findCourseIndex(courseCode);
        if (index == -1)
            return false;
        if (!courses[index].hasPrerequisite())
            return true;
        return courses[index].getPrerequisiteCode() == completedCode;
    }
    int getCourseCount()
    {
        return courseCount;
    }
    int getTotalCreditHours()
    {
        int total = 0;
        for (int i = 0; i < courseCount; i++)
        {
            total = total + courses[i].getCreditHours();
        }
        return total;
    }
    void displayAll()
    {
        cout << "=== Course Registry ===" << endl;
        for (int i = 0; i < courseCount; i++)
        {
            courses[i].display();
            cout << endl;
        }
    }
};
