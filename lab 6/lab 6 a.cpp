#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class ADTQueue{

private:
    Node* front;
    Node* rear;

public:
    ADTQueue(){
        front = nullptr;//head
        rear = nullptr;//back
    }

    bool empty(){
    if(front == nullptr)
        return true;
    else
        return false;
    }

    void append(int num){
        if(rear != nullptr){
            rear->next = new Node;
            rear = rear->next;
            rear->data = num;
            rear->next = nullptr;
        }
        else{
            front = rear = new Node;
            front->data = num;
            front->next = nullptr;
        }
    }

    int serve(){
        int num;
            if( !empty() ){
                num = front->data;
                Node* temp = front;
                front = front->next;
                delete temp;
                if (front == nullptr)
                rear = nullptr;
                return num;
            }
            else{
                cout<<"Queue is Empty";
                exit(EXIT_FAILURE);
            }
    }
    void traverse(){
        Node* temp;
        temp = front;
        while(temp !=nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main(){
    ADTQueue q;
    int num,number_entered,total=0,queue_number;
    cout<<"How many integers you want to append into the queue? : ";
    cin>>num;cout<<endl;

    for(int x=0;x<num;x++){
        cout<<"Enter integer "<<x+1<<" to the queue : ";
        cin>> number_entered;
        q.append(number_entered);
    }

    cout<<"\nThe integers that were append onto the queue are : "<<endl;
    q.traverse();

    for(int y=0;y<num;y++){
        total += q.serve();

    }

    cout<<"\n\nThe sum of the integers is : "<<total;
    cout<<endl;
}
