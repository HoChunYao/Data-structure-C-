//Q5
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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


