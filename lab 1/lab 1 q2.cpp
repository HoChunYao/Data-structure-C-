//Q2
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


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

