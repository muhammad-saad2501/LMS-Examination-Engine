#include "Assessment.h"

class CourseGrade
{
    private:
    string courseCode;
    string courseName;
    int creditHours;
    Assessment assessments[5];
    int assessmentCount;
    double totalWeight;
    public:
 
    CourseGrade()
    {
        courseCode = "";
        courseName = "";
        creditHours = 3;
        assessmentCount = 0;
        totalWeight = 0;
    }
   
    CourseGrade(string code, string name, int ch)
    {
        courseCode = code;
        courseName = name;
        setCreditHours(ch);
        assessmentCount = 0;
        totalWeight = 0;
    }
  
    void setCreditHours(int ch)
    {
        if (ch >= 1 && ch <= 4)
            creditHours = ch;
        else
            creditHours = 3;
    }
 
    bool addAssessment(Assessment a)
    {
        if (assessmentCount >= 5)
        {
            cout << "Maximum 5 assessments allowed!" << endl;
            return false;
        }
        if (totalWeight + a.getWeight() > 100)
        {
            cout << "Total weight cannot be more than 100%!" << endl;
            return false;
        }
        assessments[assessmentCount] = a;
        assessmentCount++;
        totalWeight = totalWeight + a.getWeight();
        return true;
    }
  
    string getCourseCode()
    {
        return courseCode;
    }
    string getCourseName()
    {
        return courseName;
    }
    int getCreditHours()
    {
        return creditHours;
    }
   
    double getPercentage()
    {
        double total = 0;
        for (int i = 0; i < assessmentCount; i++)
        {
            total = total + assessments[i].getWeightedScore();
        }
        return total;
    }

    string getLetterGrade()
    {
        double p = getPercentage();
        if (p >= 90)
            return "A";
        else if (p >= 80)
            return "B";
        else if (p >= 70)
            return "C";
        else if (p >= 60)
            return "D";
        else
            return "F";
    }
  
    double getGradePoints()
    {
        double p = getPercentage();
        if (p >= 90)
            return 4.0;
        else if (p >= 80)
            return 3.0;
        else if (p >= 70)
            return 2.0;
        else if (p >= 60)
            return 1.0;
        else
            return 0.0;
    }
    void display()
    {
        cout << courseCode << " - " << courseName << " (" << creditHours << " credit hours)" << endl;
        for (int i = 0; i < assessmentCount; i++)
        {
            assessments[i].display();
        }
        cout << "  Percentage: " << int(getPercentage() * 100) / 100.0 << "%" << endl;
        cout << "  Grade: " << getLetterGrade() << " (" << getGradePoints() << " points)" << endl;
    }
};
