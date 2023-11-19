#include<iostream>
using namespace std;
struct Student
{
    int roll;
    string name;
    char fname[12];
    char sname[12];
    char gender;
    int age;
    float marks;
};

int main()
{
    int num;
    cout << "\nEnter the number of students: ";
    cin >> num;
    struct Student s[num];
    cout << "\nEnter informaation of students\n";
    cout << "---------------------------------\n";
    for (int i = 0; i < num; i++)
    {
        s[i].roll = i + 1;
        cout << "For Roll Number" << s[i].roll;
        cout << "\nEnter name: ";
       cin >> s[i].name;
        cout << "\nEnter age: ";
        cin >> s[i].age;
        cout << "\nEnter marks: ";
        cin >> s[i].marks;
        cout << endl;

    }
    cout << "Student Records" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << "\nRoll Number: " << i + 1 << endl;
        cout << "           Name:" << s[i].name << endl;
        cout << "           Age:" << s[i].age << endl;
        cout << "          Marks:" << s[i].marks << endl;
    }
    return 0;
}
