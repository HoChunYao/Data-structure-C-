#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class ADTStack{
private:
    Node* top;
public:
    ADTStack(){top = nullptr;}
    bool empty(){
        if(top == nullptr)
            return true;
        else
            return false;
    }

    void push(int num){
    Node* temp;
    temp = new Node;
    temp->data = num;
        if(top == nullptr){
            top = temp;
            temp->next = nullptr;
        }
        else{
            temp->next = top;
            top = temp;
        }
    }

    int pop(){
        int num;
        Node* temp;
        if( !empty() ){
            num = top->data;
            temp = top;
            top = top->next;
            delete temp;
            return num;
        }
        else{
            cout<<"Stack is Empty";
            exit(EXIT_FAILURE);
        }
    }
};

int main(){
    int choose,num,Size=0;
    ADTStack sk;

    cout<<"1: Push "<<endl;
    cout<<"2: Pop  "<<endl;
    cout<<"3: Exit "<<endl;

    do{
        cout<<"\nChoose operation to perform : ";
        cin>>choose;
        if(choose==1){
            cout<<"Enter a number to push : ";
            cin>>num;
            sk.push(num);
            cout<<endl;
            Size ++;
        }
        else if(choose==2){
            cout<<"Number popped : "<<sk.pop()<<endl;
            Size --;
        }
    }while(choose == 1 || choose == 2 );

    cout<<"Data in the stack : "<<endl;
    for(int x=0;x<Size;x++){
        cout<<sk.pop()<<" ";
    }
}
