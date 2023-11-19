#include<iostream>
using namespace std;

struct node{
    int data;
    node *link;
}*head,*ptr,*temp;

int main(){
    ptr = new node;
    ptr->data = 35;
    ptr->link = nullptr;

    head = new node;
    head->data = 53;
    head->link = ptr;

    ptr=new node;
    ptr->data = 77;
    ptr->link = head->link;
    head->link = ptr;

    temp =new node;
    temp->data=22;
    temp->link=nullptr;
    ptr->link->link=temp;

    temp =new node;
    temp->data=105;
    temp->link=ptr->link;
    head->link=temp;
    ptr->link=nullptr;
    delete ptr;

    ptr=head;
    while(ptr!=nullptr){
        cout<<ptr->data<<endl;
        ptr = ptr->link;
    }

}
