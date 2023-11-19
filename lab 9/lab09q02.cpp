#include <iostream>
using namespace std;

struct Student
{
    int id;
    string name;
    char grade;
};

int minimum(Student s[], int SIZE, int pos)
{
    int index = pos;
    Student mini = s[pos];
    for (int i=pos+1; i<SIZE; ++i)
    {
        if ( s[i].grade < mini.grade )
        {
            index = i;
            mini = s[i];
        }
    }
    return index;
}

int main(int argc, char* argv[])
{
    const int SIZE = 5;

    Student s[SIZE], current;

    for (int i=0; i<SIZE; ++i)
    {
        cout << "Student #" << i+1 << endl;
        cout << "--------------" << endl;
        cout << "ID: ";
        cin >> s[i].id;
        cout << "Name: ";
        cin >> s[i].name;
        cout << "Grade (A, B, C, D or F): ";
        cin >> s[i].grade;
        cout << endl;
    }


    // sorting algorithm: ? selection sort
    // diy
    for (int i=0; i<SIZE-1; ++i)
    {
        int mini = minimum(s, SIZE, i);
        swap(s[i], s[mini]);
    }


    cout << "Ranking of Students" << endl;
    cout << "-------------------" << endl;
    cout << "Rank\tID\tName\tGrade" << endl;
    for (int i=0; i<SIZE; ++i)
    {
        cout << i+1 << "\t" << s[i].id << "\t" << s[i].name << "\t" << s[i].grade;
        cout << endl;
    }


    return 0;
}


