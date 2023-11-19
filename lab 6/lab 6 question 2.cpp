#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *list, *ptr;

int main(){
    ptr =new Node;
    ptr->data= 46;
    ptr->next = nullptr;
    list = new Node;
    list->data = 80;
    list->next = ptr;
    ptr = new Node;
    ptr->data = 35;
    ptr->next = list;
    list = ptr;
    ptr = new Node;
    ptr->data = 75;
    ptr->next = list->next;
    list->next = ptr;
    ptr = list;
    while (ptr){
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }
}
