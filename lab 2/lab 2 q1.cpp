//lab 2 Q1
#include<iostream>
#include<string>
using namespace std;

struct employee{
string name;
float salary;
};

int main(){
    int num_emp;
    cout<<"Enter number of employees : ";
    cin>>num_emp;

    employee *E;

    E = new employee [num_emp];

    for(int x=0;x<num_emp;x++){
        cout<<"\nEmployee "<<x+1<<endl;
        cout<<"\tEnter name : ";
        cin>>(E+x)->name;
        //cin.ignore();
        cout<<"\tEnter salary : ";
        cin>>(E+x)->salary;
    }

    cout<<"\n*****Employee Details*******"<<endl;

    for(int y=0;y<num_emp;y++){
        cout<<"\nName : "<<(E+y)->name<<endl;
        cout<<"Salary : "<<(E+y)->salary<<endl;
    }

    delete [] E;
}
