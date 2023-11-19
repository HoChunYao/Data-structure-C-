#include <iostream>
using namespace std;
const int SIZE = 5;
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
    char ch[SIZE];
    cout<<"Key in five characters : ";
    cin>>ch[0]>>ch[1]>>ch[2]>>ch[3]>>ch[4];
    for(int x=0;x<SIZE;x++){
        st.push(ch[x]);
    }
    cout<<"The reverse order is : ";
    for(int y=0;y<SIZE;y++){
        cout<<st.pop()<<" ";
    }
}
