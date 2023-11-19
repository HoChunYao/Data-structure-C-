#include <iostream>
using namespace std;
const int SIZE = 10;
class ADTStack
{
private:
    char stack[SIZE];
    int topstack;
public:
    ADTStack(){
        topstack = -1;
    }
bool empty(){
    if(topstack == -1)
        return true;
    else
        return false;
    }
bool full(){
    if(topstack == SIZE-1)
        return true;
    else
        return false;
}
void push(char ch){
    if (!full()){
        topstack++;
        stack[topstack] = ch;
    }
    else{
        cout<<"Stack is full"<<endl;
        exit(EXIT_FAILURE);
    }
}
char pop(){
char ch;
    if(!empty()){
        ch = stack[topstack];
        topstack--;
        return ch;
    }
    else{
        cout<<"Stack is empty"<<endl;
        exit(EXIT_FAILURE);
    }
}

};

int main(){
    ADTStack st;
    int num[SIZE];
    int even_num = 0; int odd_num = 0;
    cout<<"Key in 10 numbers : ";
    for(int i=0;i<SIZE;i++){

        cin>>num[i];
        st.push(num[i]);
    }

    for(int x=0;x<SIZE;x++){
        if(st.pop()%2 == 0){
            even_num ++;
        }
        else
            odd_num ++;
    }

    cout<<"There are "<<even_num<<" even numbers and "<<odd_num<<" odd numbers"<<endl;

}
