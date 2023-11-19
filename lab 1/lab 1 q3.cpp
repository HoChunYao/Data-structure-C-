//Q3
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

