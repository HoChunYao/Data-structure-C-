//normal linked list - not using template <T>
//operation:
//1. append node - add node to the backside             (done)
//2. insert node - one node/value only                  (done)
//3. delete node - one node only                        (done)
//4. display value -all value                           (done)
//5. using destructor to delete or destroy all node     (
//6. to find value in the node ***                      (done)
//7. to find max value                                  (done)
//8. to find min value                                  (done)
//9. to find middle value                               (
//10. isEmpty function                                  (done)
//11. delete front                                      (
//12. delete back                                       (
//13. insert front                                      (
//14. using file (input and output)?????                (
#include<iostream>
#include<fstream>
using namespace std;

struct ListNode{
    int value;  // the value in this node
    ListNode* next; // to point to the next node
};

class LinkedList{
 private:
    //list head pointer
    ListNode* head;
 public:
    //constructor
    LinkedList(){head = nullptr;}//set a new node
    //destructor - destory all the element in the list
    //~LinkedList()

    //add the node to the end of the list
    void appendNode(int num){
        ListNode *newNode;//to point to a new node
        ListNode *nodePtr;//to move through the list

        //allocate a new node and store num there
        newNode = new ListNode;
        newNode->value =num;
        newNode->next = nullptr;

        //If there are no nodes in the list
        //make newNode the first node.
        if(!head)
            head = newNode;
        //Otherwise, insert newNode at end
        else{
            //initialize nodePtr to head of list
            nodePtr =head;//node *nodePtr =head;
            //find the last node in the list
            while(nodePtr->next)
                nodePtr = nodePtr->next;
            //insert newNode as the last node
            nodePtr->next =newNode;
        }

    }

    //to add value into the list and based on the num
    void insertNode(int num){
        ListNode *newNode; // create new node
        ListNode *nodePtr; // to traverse the list
        ListNode *previousNode = nullptr; // the previous node

        //allocate a new node and store num there
        newNode = new ListNode;
        newNode->value = num;

        //if there are no nodes in the list
        //make newNode the first node
        if(!head){
            head = newNode;
            newNode->next=nullptr;
        }
        //otherwise, insert newNode
        else{
            //position nodePtr at the head list
            nodePtr =head;
            //initialize previousNode to nullptr
            previousNode =nullptr;
            //skip all node whose value is less than num
            while(nodePtr != nullptr && nodePtr->value < num){
                previousNode =nodePtr;
                nodePtr = nodePtr->next;
            }
        //if the new node is to be the 1st in the list
        //insert it before all other nodes
            if(previousNode == nullptr){
                head = newNode;
                newNode->next =nodePtr;
            }
        //otherwise insert after the previous node
            else{
                previousNode->next =newNode;
                newNode->next =nodePtr;
            }
        }
    }

    //delete one node only
    void deleteNode(int num){
        ListNode *nodePtr;          //traverse the list
        ListNode *previousNode;     //point to the previous node

        //if the list is empty , do nothing
        if(!head){
            return;
        }
        //determine if the first node is the one
        if(head->value ==num){
            nodePtr=head->next;
            delete head;
            head = nodePtr;
        }
        else{
            //initialize nodePtr to head of list
            nodePtr = head;

            //skip all nodes whose value member is not equal to num
            while(nodePtr != nullptr && nodePtr->value != num){
                previousNode =nodePtr;
                nodePtr = nodePtr->next;
            }
            //if nodePtr is not at the end of the list .
            //link the previous node to the node after
            //nodePtr, then delete nodePtr
            if(nodePtr){
                previousNode->next=nodePtr->next;
                delete nodePtr;
            }
        }
    }

    //display value
    void displayList()const{
        ListNode *nodePtr; //to move through the list

        //position nodePtr at the head of the list
        nodePtr = head;

        //while nodePtr points to a node ,traverse the list
        while(nodePtr){
            //display the value in the node
            cout<<nodePtr ->value <<endl;
            //move to the next node
            nodePtr = nodePtr->next;
        }
    }

    //determine empty value
    bool isEmpty(){ return head == nullptr;}

    //find maximum value
    int findMax(){
        ListNode *temp = head;
        int max = INT_MIN;
            while(temp != NULL){
                if(max<temp -> value)
                    max = temp -> value;
                temp = temp ->next;
            }
        return max;
    }

    //find minimum value
    int findMin(){
        ListNode *temp = head;
        int min = INT_MAX;
        int size =10;
        for(int i = 0; i < size; i++){
            while (temp != NULL){
                    if (temp->value < min)
                        min = temp->value;
                    temp = temp->next;
            }
         }
         return min;
    }

    //Insert number to the backside
    void insertback(int num){
        ListNode *nodePtr;
        nodePtr = new ListNode;
        nodePtr->value = num; //assign num to the nodePtr->data;
        if(head == nullptr){
            head = nodePtr;
            nodePtr->next =nullptr;
        }
        else{
            nodePtr->next=head;
            head=nodePtr;
        }
    }

    bool findValue(int num){
        bool found = false;
        ListNode *temp =head;
        while((temp->next)!= nullptr && !found){
            if((temp->value)== num){
                found = true;
            }
            else{
                 temp=temp->next;
            }
        }
        return found;
    }
};

int main(){
    LinkedList list;
    struct ListNode* head = NULL;
    int num,found;
    list.appendNode(3);
    list.appendNode(7);
    list.appendNode(9);
    list.insertNode(5);
    list.appendNode(1);
    list.displayList();
    cout<<"-------------------------------------------------"<<endl;
    list.deleteNode(7);
    list.insertback(20);
    list.insertback(70);
    list.displayList();
    cout<<"-------------------------------------------------"<<endl;
    cout<<"Enter your searching value : ";cin>>num;
    found=list.findValue(num);
    if(found == 1)
        cout<<"data found : "<<num<<endl;
    else
        cout<<"data not found" <<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"Max number : "<<list.findMax()<<endl;
    cout<<"Min number : "<<list.findMin()<<endl;

}
