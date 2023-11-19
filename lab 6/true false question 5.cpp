#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*head,*ptr,*temp;

int main(){
    ptr=new Node;
    ptr->data=50;
    ptr->next=nullptr;
    head=new Node;
    head->data =40;
    head->next=ptr;
    ptr=new Node;
    ptr->data=30;
    ptr->next=head;
    head= new Node;
    head->data=20;
    head->next=ptr;
    //ptr=head;
    cout<<head->next->next->next->next->data<<endl;
   /* while(ptr){
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }*/
}
