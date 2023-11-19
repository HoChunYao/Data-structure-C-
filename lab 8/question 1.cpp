#include<iostream>
using namespace std;

int main(){
    const int size = 5;
    int number[size];
    int hashValue[size];
    int i =0;
    do{
        cout<<"Enter key "<<i+1<<": ";
        cin>>number[i];
        if(number[i]>9999 || number[i]<1000){
            cout<<"Error : Input out of range "<<endl;
        }
        else{
            i++;
        }
    }while(i<size);
    for(int j=0;j<size;j++){
        hashValue[j]=number [j]/100;
        cout<<"Key : "<<numbery[j]<<"\tHash value: "<<hashValue[j]<<endl;
    }
}
