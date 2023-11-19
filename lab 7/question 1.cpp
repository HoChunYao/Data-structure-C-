#include<iostream>
using namespace std;
int search(int a[], int size, int y);

int main(){
    int size, a[100], y, position;

    cout<<"Enter array size: ";
    cin>>size;

    for(int i=0; i<size; i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>a[i];
    }

    cout<<"Enter element to search: ";
    cin>>y;

    position = search(a, size, y);

    if( position != -1 )
        cout<<"Element found at index "<<position<<endl;
    else
        cout<<"Element is not found"<<endl;
    return 0;
}
//y = target , size = high
int search(int a[], int size, int y){
    int first =0,last=size-1;
    while(first <= last){
       int mid = (first + last) /2;

        if(a[mid]== y)
            return mid;

        else if(a[mid]<y)
            first = mid + 1;

        else
            last = mid - 1;
    }

    return -1;
}
