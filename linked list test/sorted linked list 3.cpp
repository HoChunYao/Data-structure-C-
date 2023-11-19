#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

/* Link list node */
class Node {

    int data;
    Node* next;
    public:
    /* A utility function to create a new node */
    Node* newNode(int new_data)
    {
        /* allocate node */
        Node* new_node = new Node();

        /* put in the data */
        new_node->data = new_data;
        new_node->next = nullptr;

        return new_node;
    }
    /* function to insert a new_node in a list. Note that this function expects a pointer to head_ref as this can modify the head of the input linked list (similar to push())*/
    void sortedInsert(Node** head_ref,Node* new_node)
    {
        Node* current;
        /* Special case for the head end */
        if (*head_ref == nullptr|| (*head_ref)->data>= new_node->data)
        {
            new_node->next = *head_ref;
            *head_ref = new_node;
        }
        else
        {
            /* Locate the node before the point of insertion */
            current = *head_ref;
            while (current->next != nullptr && current->next->data < new_node->data) {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }

    void deleteFunc(Node **head, int key)
    {
        // Store head node
        Node* temp = *head;
        Node* prev = NULL;
        // If head node itself holds
        // the key to be deleted
        if (temp != NULL && temp->data == key)
        {
            *head = temp->next; // Changed head
            delete temp;            // free old head
            return;
        }
        // Else Search for the key to be deleted,
        // keep track of the previous node as we
        // need to change 'prev->next' */
        else
        {
            while(temp != NULL && temp->data != key)
            {
                prev = temp;
                temp=temp->next;
            }
            // If key was not present in linked list
            if (temp == NULL)
            return;
            // Unlink the node from linked list
            prev->next=temp->next;
            // Free memory
            delete temp;
        }
    }

    /* Function to print linked list */
    void printList(Node* head,ofstream &output_file)
    {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            output_file<<temp->data<< " ";
            temp = temp->next;
        }
      cout<<endl;
    }
};

int main()
{
    /* Start with the empty list */
    Node *new_node=nullptr,node,*head = nullptr;
    int choice,num;
    char conti;
    string myText;
    // Create and open a text file
    ofstream MyFile("filename.txt");
    ifstream MyReadFile("filename.txt");
    do
    {
        system("CLS");
        cout<<"1. add\n2. delete"<<endl;
        cout<<"Insert choice(1,2,3)"<<endl;
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter the number you wish to add : ";
            cin>>num;
            new_node=node.newNode(num);
            node.sortedInsert(&head,new_node);
            MyFile << "sll added "<<num<<endl;
        }
        else if(choice==2)
        {
            cout<<"Enter the number you wish to delete : ";
            cin>>num;
            node.deleteFunc(&head,num);
            MyFile << "sll deleted "<<num<<endl;
        }
        else
        {
            cout<<"Invalid Choice!"<<endl;
            exit(0);
        }
        cout<<"\nContinue?(Y/N)"<<endl;
        cin>>conti;
    }while(conti!='N' && conti!='n');

    cout << "Created Linked List\n";
    node.printList(head,MyFile);
    MyFile.close();

    while (getline (MyReadFile, myText)) {
    // Output the text from the file
        cout <<myText<<endl;
    }
    MyReadFile.close();
    return 0;
}
