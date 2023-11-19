#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
}*head,*temp,*ptr;

int main(){
    node *head =new node;
    head->data = 35;
    head->next = nullptr;

    node *ptr = new node;
    ptr->data = 30 ;
    ptr->next = head;
    head = ptr;

    node *temp = new node;
    temp->data = 15;
    temp->next = head;
    head = temp;

    head = new node;
    head -> data =10;
    head -> next = temp;

    ptr = new node;
    ptr->data = 27;
    ptr->next = nullptr;

    //question 1 : 27 insert to the between 15 and 30
    ptr->next = temp->next;
    temp->next = ptr;

    //question 2 :print odd data
    ptr = head;
    while(ptr != nullptr){
        if(ptr->data % 2 !=0){
            cout<<ptr->data<<endl;
        }
        ptr=ptr->next;
    }
    cout<<"----------------------"<<endl;

    //question 3 : find the last linked list data
    ptr = head;
    while(ptr !=nullptr){
        if(ptr->next == nullptr){
            cout<<ptr->data<<endl;
        }
        ptr=ptr->next;
    }

    cout<<"----------------------"<<endl;

    //question 4 : delete last element
    ptr =head;
    while(ptr !=nullptr){
        if(ptr->next == nullptr){
            temp =new node;
            temp = ptr->next;
            temp->next=nullptr;
            delete temp;
        }
        else{
            cout<<ptr->data<<endl;
            ptr = ptr->next;
        }
    }

    cout<<"----------------------"<<endl;

    ptr=head;
    while(ptr !=nullptr){
        cout<<ptr->data<<endl;
        ptr =ptr->next;
    }
}
