#include<iostream>
using namespace std;

int search(int a[], int size, int y){
    int first =0,last=size-1;
    while(first <= last){
       int mid = first +(last - first)/2;

        if(a[mid]== y)
            return mid;

        else if(a[mid]<y)
            first = mid + 1;

        else
            last = mid - 1;
    }

    return -1;
}

int main(){
    const int size = 100;
    int array[size]={90,85,80,70,65,56,40,20};
    int target,first,last,mid;

    bool found = false;

    first =0;
    last = size - 1;

    cout<<"Input the target >> ";
    cin>>target;



    if(found)
        cout<<"\nPosition index : "<<mid <<endl;
    else
        cout<<"\nTarget is NOT FOUND" <<endl;

    return 0;
}
