#include "Gradebook.h"

int main()
{
    string name;
    int id;

    cout << "Enter student name (one word): ";
    cin >> name;
    cout << "Enter student ID: ";
    cin >> id;

    Gradebook gradebook(name, id);

    gradebook.addCourse("CS201", "Object Oriented Programming", 3);
    gradebook.addCourse("CS201L", "Object Oriented Programming Lab", 1);
    gradebook.addCourse("CS202", "Computer Organization and Assembly Language", 3);

    string codes[3] = {"CS201", "CS201L", "CS202"};

    for (int i = 0; i < 3; i++)
    {
        double quiz, midterm, final;

        cout << endl << "Enter marks for " << codes[i] << endl;
        cout << "Quiz (out of 10): ";
        cin >> quiz;
        cout << "Midterm (out of 50): ";
        cin >> midterm;
        cout << "Final (out of 100): ";
        cin >> final;

        gradebook.addAssessment(codes[i], "Quiz", quiz, 10, 20);
        gradebook.addAssessment(codes[i], "Midterm", midterm, 50, 30);
        gradebook.addAssessment(codes[i], "Final", final, 100, 50);
    }

    cout << endl;
    gradebook.displayTranscript();

    return 0;
}
