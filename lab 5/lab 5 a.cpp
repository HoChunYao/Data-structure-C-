#include <iostream>
#include <string>
using namespace std;

template <typename T>//can be any data type by declared variable for struct
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>//can be any data type by declared variable for class
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() { head = nullptr; }
    ~LinkedList() { makeEmpty(); }

// inserts at the beginning of the linked list
void insertFront(T& element) {
    Node<T>* newNode = new Node<T>;
    newNode->data = element;
    newNode->next = head;
    head = newNode;
    }

// inserts at the ending of the linked list
void insertBack(T& element) {
    Node<T>* newNode = new Node<T>;
    newNode->data = element;
    newNode->next = nullptr;
    if(head == nullptr) {//!head
       head = newNode;
       return;
    }
    Node<T>* temp = head;
while(temp->next != nullptr) {
        temp =temp->next;
    }
    temp->next = newNode;
    }

// deletes at the beginning of the linked list
void deleteFront() {
    if(head == nullptr) {
        return;
    }
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

// returns true if element is found; returns false if element is no found
bool find(T& target) {
    bool found = false;
    Node<T>* ptr = head;
    while (ptr != nullptr && !found) {
    if (ptr->data == target) {
    found = true;
    }
    else
    ptr = ptr->next;
    }
    return found;
    }
bool isEmpty() { return head == nullptr; }

void makeEmpty() {
    while (head != nullptr) {
    Node<T>* ptr = head;
    head = head->next;
    delete ptr;
    }
}

friend ostream& operator<< (ostream& os, LinkedList<T>& list) {
    Node<T>* ptr = list.head;
    while (ptr != nullptr) {
        os << ptr->data << " ";
        ptr = ptr->next;
        }
    return os;
    }
};

int main(){
    int num;
    LinkedList<int> Linked;//object == linked
    //enter data by user
    for(int i=0;i<5;i++)
    {
        cout<<"Enter data "<<i+1<<": ";
        cin>>num;
        Linked.insertBack(num);
    }

    //output the list
    cout<<"The Current List:"<<endl;
    cout<<Linked<<endl<<endl;

    //delete the node in the list and just delete first one only
    cout<<"Deleting the first node"<<endl;
    cout<<"The list after deletion: "<<endl;
    Linked.deleteFront();
    cout<<Linked<<endl<<endl;

    //data searching function
    cout<<"Enter a data to search: ";
    cin>>num;

    //assignment the f into Linked.find(num) in order to return 1(true) and 0(false) to the function
    bool f = Linked.find(num);
    if(f=true)
    {
        cout<<"DATA FOUND!"<<endl;
    }
    else
    {
        cout<<"DATA NOT FOUND!"<<endl;
    }
    return 0;
}

