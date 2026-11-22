#include <iostream>
#include <string>
using namespace std;

class Assessment
{
    private:
    string name;
    double obtainedMarks;
    double totalMarks;
    double weight;   
    public:
   
    Assessment()
    {
        name = "";
        obtainedMarks = 0;
        totalMarks = 100;
        weight = 0;
    }
   
    Assessment(string n, double obtained, double total, double w)
    {
        name = n;
        setTotalMarks(total);
        setObtainedMarks(obtained);
        setWeight(w);
    }
    
    void setName(string n)
    {
        name = n;
    }
    void setTotalMarks(double t)
    {
        if (t > 0)
            totalMarks = t;
        else
            totalMarks = 100;
    }
    void setObtainedMarks(double o)
    {
        if (o < 0)
            obtainedMarks = 0;
        else if (o > totalMarks)
            obtainedMarks = totalMarks;
        else
            obtainedMarks = o;
    }
    void setWeight(double w)
    {
        if (w >= 0 && w <= 100)
            weight = w;
        else
            weight = 0;
    }
   
    string getName()
    {
        return name;
    }
    double getObtainedMarks()
    {
        return obtainedMarks;
    }
    double getTotalMarks()
    {
        return totalMarks;
    }
    double getWeight()
    {
        return weight;
    }
  
    double getWeightedScore()
    {
        return (obtainedMarks / totalMarks) * weight;
    }
    void display()
    {
        cout << "  " << name << ": " << obtainedMarks << "/" << totalMarks
             << " (weight " << weight << "%)" << endl;
    }
};
