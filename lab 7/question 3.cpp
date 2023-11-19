#include<iostream>
using namespace std;

// first one
char grade(int num ,int b[]){
    char grade;
    int i =num;
    if(b[i]<100 && b[i]>=80)
        grade = 'A';
    else if(b[i]<80 && b[i]>=60)
        grade = 'B';
    else if(b[i]<60 && b[i]>=50)
        grade = 'C';
    else if(b[i]<50 && b[i]>=40)
        grade = 'D';
    else if(b[i]<40 && b[i]>=0)
        grade = 'F';
    return grade;
}

//first one
int search(int a[],int b[],int size,int target){
    for(int i=0;i<size;i++)
        if(a[i]== target)
            return i;
    return -1;
}

int main(){
    const int size =5;
    //second one done
    int student_id[size],mark[size],target;
    cout<<"Please enter student IDs and marks : \n\n";

    for(int i=0;i<size;i++){
        cout<<"Student "<<i+1<<" ID : ";
        cin>>student_id[i];
        cout<<"Student "<<i+1<<" mark : ";
        cin>>mark[i];
    }
    cout<<"Enter the student ID that you want to search : ";
    cin>>target;
    //third one
    int num = search( student_id,mark,size,target);
    if(num!=-1){
        cout<<"Target found"<<endl<<endl;
        cout<<"The mark of student ID "<<student_id[num]<<" is "<<mark[num]<<" . The grade is "<<grade(num,mark)<<endl;
    }
    else
        cout<<"Target not found"<<endl;
}

