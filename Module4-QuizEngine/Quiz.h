#include "Question.h"

class Quiz
{
    private:
    string quizId;
    Question questions[10];
    int questionCount;
    int score;
    int totalPoints;
    public:
    Quiz(string id)
    {
        quizId=id;
        questionCount=0;
        score=0;
        totalPoints=0;
    }
    bool addQuestion(Question q)
    {
        if(questionCount>=10)
        {
            cout<<"Quiz is Full!"<<endl;
            return false;
        }
        questions[questionCount]=q;
        questionCount++;
        totalPoints = totalPoints + q.getPoints();
        return true;
    }
    void takeQuiz()
    {
        score=0;
        cout<<"=== Quiz "<<quizId<<" ==="<<endl<<endl;
        for(int i=0;i<questionCount;i++)
            {
                cout<<"Q"<<i+1<<". ";
                questions[i].display();
                char answer;
                cout<<"Your Answer: ";
                cin>>answer;
                if(questions[i].checkAnswer(answer))
                {
                    score=score+questions[i].getPoints();
                    cout<<"> CORRECT (+"<<questions[i].getPoints()<<" pts)"<<endl<<endl;
                }
                else
                {
                    cout<<"> WRONG"<<endl<<endl;
                }
            }
    }
    string getQuizId()
    {
        return quizId;
    }
    int getScore()
    {
        return score;
    }
    int getTotalPoints()
    {
        return totalPoints;
    }
    double getPercentage()
    {
        if(totalPoints==0)
            return 0;
        return (score*100.0)/totalPoints;
    }
    void showResult()
    {
        cout<<"Quiz Score: "<<score<<"/"<<totalPoints<<" ("<<getPercentage()<<"%)"<<endl;
    }
};
