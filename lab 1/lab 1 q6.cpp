//Q6
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int Sum(int num[],int total,int Size){
	for(int x=0;x<Size;x++){
		cout<<"Enter number "<<x+1<<" : ";
		cin>>num[x];
		total += num[x];
	}
	return total;
}

int main(){
    const int Size =5;
	int num[Size],total;

	cout<<"Enter five numbers and the program will calculate sum of the number ."<<endl;
	total =Sum(num,total,Size);
	cout<<"You have entered : "<<num[0]<<" , "<<num[1]<<" , "<<num[2]<<" , "<<num[3]<<" , "<<num[4]<<endl;
	cout<<"Sum of the number entered is : "<<total;

}
