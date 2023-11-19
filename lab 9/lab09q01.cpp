#include <iostream>
using namespace std;

struct Student
{
    int id;
    string name;
    char grade;
};

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


    // sorting algorithm: ? insertion sort
    // diy
    for (int i=1; i<SIZE; ++i)
    {
        current = s[i];
        int j = i;
        while ( s[j-1].grade > current.grade )
        {
            swap(s[j], s[j-1]);
            j--;
            current = s[j];
        }
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



