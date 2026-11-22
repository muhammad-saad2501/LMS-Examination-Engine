#include "CourseGrade.h"

class Gradebook
{
    private:
    string studentName;
    int studentId;
    CourseGrade courses[10];
    int courseCount;
    
    int findCourseIndex(string code)
    {
        for (int i = 0; i < courseCount; i++)
        {
            if (courses[i].getCourseCode() == code)
                return i;
        }
        return -1;
    }
    public:
    Gradebook(string name, int id)
    {
        studentName = name;
        if (id > 0)
            studentId = id;
        else
            studentId = 0;
        courseCount = 0;
    }
    bool addCourse(string code, string name, int creditHours)
    {
        if (courseCount >= 10)
        {
            cout << "Gradebook is full!" << endl;
            return false;
        }
        if (findCourseIndex(code) != -1)
        {
            cout << "Course " << code << " already exists!" << endl;
            return false;
        }
        CourseGrade c(code, name, creditHours);
        courses[courseCount] = c;
        courseCount++;
        return true;
    }
    bool addAssessment(string courseCode, string assessmentName, double obtained, double total, double weight)
    {
        int index = findCourseIndex(courseCode);
        if (index == -1)
        {
            cout << "Course " << courseCode << " not found!" << endl;
            return false;
        }
        Assessment a(assessmentName, obtained, total, weight);
        return courses[index].addAssessment(a);
    }
    string getStudentName()
    {
        return studentName;
    }
    int getStudentId()
    {
        return studentId;
    }
    double getGPA()
    {
        double totalPoints = 0;
        int totalCredits = 0;
        for (int i = 0; i < courseCount; i++)
        {
            totalPoints = totalPoints + courses[i].getGradePoints() * courses[i].getCreditHours();
            totalCredits = totalCredits + courses[i].getCreditHours();
        }
        if (totalCredits == 0)
            return 0;
        return totalPoints / totalCredits;
    }
    void displayTranscript()
    {
        cout << "===== Transcript =====" << endl;
        cout << "Student: " << studentName << " (ID: " << studentId << ")" << endl << endl;
        for (int i = 0; i < courseCount; i++)
        {
            courses[i].display();
            cout << endl;
        }
        cout << "Cumulative GPA: " << int(getGPA() * 100) / 100.0 << endl;
    }
};
