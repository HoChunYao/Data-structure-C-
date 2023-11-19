#include <iostream>
using namespace std;

int main(){
    int num1=10,num2=20,array[3]={2,4,6};
    int &num3 = num2;
    int *ptr1,*ptr2;

    //example: ptr1 pointing to num1
        ptr1 = &num1;
    //assign value stored in ptr1 to ptr2
        ptr2 = ptr1;
    //ptr1 pointing to the first element in array
        ptr1 = array;
    //add value pointed to by ptr2 with 3 and store the result
    //in array element index 2, use both pointer ptr1 and ptr2
    //in your answer.
        *(ptr1+2) = *ptr2 +3;
    //add value pointed to by ptr1 with 4 and store in num3
        num3 = *ptr1 +4;

        //cout<<*ptr1<<" "<<endl;//<<*ptr2<<" "<<endl;
       // cout<<ptr1<<" "<<ptr2<<" "<<endl;
        cout<<num1<<" "<<num2<<" "<<num3<<endl;
        for(int x=0;x<3;x++)
            cout<<"number of array[ "<<x<<" ] : "<<array[x]<<endl;
}

