#include <iostream>

#include <bits/stdc++.h>
using namespace std;

//Q1
/*

int main(){
    int n1,n2,n3,n4,maximum;

    cout<<"Enter four integers : ";
    cin>>n1>>n2>>n3>>n4;

    maximum = n1;
    if(maximum < n2) maximum =n2;
    if(maximum < n3) maximum =n3;
    if(maximum < n4) maximum =n4;
    cout<<"maximum number : "<<maximum<<endl;

}
*/

//Q2



int main(){
    int num;

    do{
    	cout<<"Type a number (0 to exit) : ";
    	cin>> num;
    	if(num != 0){
    		if(num %2 == 0){
    			cout<<num<<" is even."<<endl;
			}
			else if(num %2 != 0){
				cout<<num<<" is odd."<<endl;
			}
		}
		else
			cout<<"thank you."<<endl;
	}while(num != 0);

}


//Q3
/*
int main(){
    char operation;
    int n1,n2,total;
    cout<<"Enter an operator (+,-,*,/) : ";
    cin>>operation;
    cout<<"Enter two operands : ";
    cin>>n1>>n2;

    switch(operation){
        case '+':
            total = n1 + n2 ;
            cout<<n1<<" "<<operation<<" "<<n2<<" = "<<total<<endl;
            break;
		case '-':
            total = n1 - n2 ;
            cout<<n1<<" "<<operation<<" "<<n2<<" = "<<total<<endl;
            break;
        case '*':
            total = n1 * n2 ;
            cout<<n1<<" "<<operation<<" "<<n2<<" = "<<total<<endl;
            break;
        case '/':
            total = n1 / n2 ;
            cout<<n1<<" "<<operation<<" "<<n2<<" = "<<total<<endl;
            break;
    }
}
*/

//Q4

/*
int main(){
	for(int x=1;x<6;x++){

		for(int y=1;y<=x;y++){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}
*/

//Q5

/*

int main(){
	int mark[5],total,avg;
	int size = *(&mark + 1) - mark;
	for(int x=0;x<5;x++){
		cout<<"Enter mark : ";
		cin>>mark[x];
		total += mark[x];
	}
	avg = total / size;
	cout<<"Mark average is : "<<avg<<endl;
}

*/

//Q6

/*

int Sum(int num[],int total){
	for(int x=0;x<5;x++){
		cout<<"Enter number "<<x+1<<" : ";
		cin>>num[x];
		total += num[x];
	}
	return total;
}

int main(){
	int num[5],total;

	cout<<"Enter five numbers and the program will calculate sum of the number ."<<endl;
	total =Sum(num,total);
	cout<<"You have entered : "<<num[0]<<" , "<<num[1]<<" , "<<num[2]<<" , "<<num[3]<<" , "<<num[4]<<endl;
	cout<<"Sum of the number entered is : "<<total;

}

*/

//Q7

/*
struct employee{
	string first_name,last_name,emplo_num;
	int age;
};

int main(){
	employee E;
	cout<<"First name      : ";cin>>E.first_name;
	cout<<"Last name       : ";cin.ignore();getline(cin,E.last_name);
	cout<<"Employee number : ";cin>>E.emplo_num;
	cout<<"Age             : ";cin>>E.age;

	cout<<endl<<"Hello "<<E.first_name<<" "<<E.last_name<<endl
	<<"Your employee number "<<E.emplo_num<<endl
	<<"Your are "<<E.age<<" years old "<<endl;
}

*/
