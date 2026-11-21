#include "Instructor.h"

class Course
{
    private:
    string code;
    string name;
    int creditHours;
    string prerequisiteCode;
    Instructor instructor;
    bool instructorAssigned;
    public:
    Course()
    {
        code = "";
        name = "";
        creditHours = 3;
        prerequisiteCode = "";
        instructorAssigned = false;
    }
    Course(string c, string n, int ch, string prereq)
    {
        code = c;
        name = n;
        setCreditHours(ch);
        prerequisiteCode = prereq;
        instructorAssigned = false;
    }
    void setCode(string c)
    {
        code = c;
    }
    void setName(string n)
    {
        name = n;
    }
    void setCreditHours(int ch)
    {
        if (ch >= 1 && ch <= 4)
            creditHours = ch;
        else
            creditHours = 3;
    }
    void setPrerequisiteCode(string p)
    {
        prerequisiteCode = p;
    }
    void assignInstructor(Instructor i)
    {
        instructor = i;
        instructorAssigned = true;
    }
    string getCode()
    {
        return code;
    }
    string getName()
    {
        return name;
    }
    int getCreditHours()
    {
        return creditHours;
    }
    string getPrerequisiteCode()
    {
        return prerequisiteCode;
    }
    bool hasPrerequisite()
    {
        return prerequisiteCode != "";
    }
    void display()
    {
        cout << code << " - " << name << " (" << creditHours << " credit hours)" << endl;
        if (hasPrerequisite())
            cout << "  Prerequisite: " << prerequisiteCode << endl;
        else
            cout << "  Prerequisite: None" << endl;
        if (instructorAssigned)
        {
            cout << "  Instructor: ";
            instructor.display();
        }
        else
            cout << "  Instructor: Not assigned" << endl;
    }
};
