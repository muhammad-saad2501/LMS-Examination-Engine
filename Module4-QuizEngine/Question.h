#include <iostream>
#include <string>
using namespace std;

class Question
{
private:
    string text;
    string options[4];    
    char correctOption;   
    int points;
public:
    Question()
    {
        text = "";
        for (int i = 0; i < 4; i++)
        {
            options[i] = "";
        }
        correctOption = 'A';
        points = 0;
    }
    Question(string t, string a, string b, string c, string d, char correct, int p)
    {
        text = t;
        options[0] = a;
        options[1] = b;
        options[2] = c;
        options[3] = d;
        setCorrectOption(correct);
        setPoints(p);
    }
    void setText(string t)
    {
        text = t;
    }
    void setCorrectOption(char c)
    {
        if (c == 'a') c = 'A';
        if (c == 'b') c = 'B';
        if (c == 'c') c = 'C';
        if (c == 'd') c = 'D';
        if (c == 'A' || c == 'B' || c == 'C' || c== 'D')
            correctOption = c;
        else
            correctOption = 'A';
    }
    void setPoints(int p)
    {
        if (p > 0)
            points = p;
        else
            points = 1;
    }
    string getText()
    {
        return text;
    }
    int getPoints()
    {
        return points;
    }
    bool checkAnswer(char answer)
    {
        if (answer == 'a') 
            answer = 'A';
        if (answer == 'b') 
            answer = 'B';
        if (answer == 'c') 
            answer = 'C';
        if (answer == 'd') 
            answer = 'D';
        if (answer == correctOption)
            return true;
        else
            return false;
    }
    void display()
    {
        cout << text << " (" << points << " pts)"<< endl;
        for (int i = 0; i < 4; i++)
        {
            cout << "  " << char('A' + i) << ") "<< options[i] << endl;
        }
    }
};



