#include<iostream>
using namespace std;

int main (){
    int id,hashValue;

    cout<<"Enter Id: ";
    cin>>id;
   hashValue = (   (id/1000000)   +  ( (id/1000)%1000 )   +  ((id/1)%1000)  )   %100  ;
    cout<<"Hash Value : "<<hashValue;
}
