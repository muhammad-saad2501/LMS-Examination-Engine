#include <iostream>
#include <string>
using namespace std;

class Instructor
{
    private:
    string name;
    int id;
    public:
    Instructor()
    {
        name = "";
        id = 0;
    }
    Instructor(string n, int i)
    {
        name = n;
        setId(i);
    }
    void setName(string n)
    {
        name = n;
    }
    void setId(int i)
    {
        if (i > 0)
            id = i;
        else
            id = 0;
    }
    string getName()
    {
        return name;
    }
    int getId()
    {
        return id;
    }
    void display()
    {
        cout << name << " (ID: " << id << ")" << endl;
    }
};
