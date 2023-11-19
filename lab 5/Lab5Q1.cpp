#include <iostream>
#include <string>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node<T>* next;
};
template <typename T>
class LinkedList
{
    private:
        Node<T>* head;
    public:
        LinkedList()
        {
            head = nullptr;
        }
        ~LinkedList()
        {
            makeEmpty();
        }
        // inserts at the beginning of the linked list
        void insertFront(T& element)
        {
            Node<T>* newNode = new Node<T>;
            newNode->data = element;
            newNode->next = head;
            head = newNode;
        }
        // inserts at the ending of the linked list
        void insertBack(T& element)
        {
            Node<T>* newNode = new Node<T>;
            newNode->data = element;

            if (head == nullptr)
            {
                head = newNode;
                newNode->next = nullptr;
            }
            else
            {
                Node<T>* temp = head;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = nullptr;
            }

            // newNode->next = nullptr;
            // if(head == nullptr)
            // {
            //     head=new Node<T>;
            // }
            // Node<T>* temp = head;
            // while(temp->next != nullptr)
            // {
            //     temp = temp->next;
            // }
            // temp->next = newNode;
        }
        // deletes at the beginning of the linked list
        void deleteFront()
        {
            if(head == nullptr)
            {
                return;
            }
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        // returns true if element is found; returns false if element is not found
        bool find(T& target)
        {
            bool found = false;
            Node<T>* ptr = head;
            while (ptr != nullptr && !found)
            {
                if (ptr->data == target)
                {
                    found = true;
                }
                else
                {
                    ptr = ptr->next;
                }
                return found;
            }
        }
        bool isEmpty()
        {
            return head == nullptr;
        }
        void makeEmpty()
        {
            while (head != nullptr)
            {
                Node<T>* ptr = head;
                head = head->next;
                delete ptr;
            }
        }
        friend ostream& operator<< (ostream& os, LinkedList<T>& list)
        {
            Node<T>* ptr = list.head;
            while (ptr != nullptr)
            {
                os << ptr->data << " ";
                ptr = ptr->next;
            }
            return os;
        }
};
int main()
{
    int num;
    LinkedList<int> l;
    for(int i=0;i<5;i++)
    {
        cout<<"Enter data "<<i+1<<": ";
        cin>>num;
        l.insertBack(num);
    }
    cout<<"The Current List:"<<endl;
    cout<<l<<endl<<endl;
    cout<<"Deleting the first node"<<endl;
    cout<<"The list after deletion: "<<endl;
    l.deleteFront();
    cout<<l<<endl;
    cout<<"Enter a data to search: ";
    cin>>num;
    if(l.find(num))
    {
        cout<<"DATA FOUND!";
    }
    else
    {
        cout<<"DATA NOT FOUND!";
    }
    return 0;
}
