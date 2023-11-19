// *********************************************************
// Program: Group08.cpp
// Course: DCP5301 DSA
// Tutorial section: TL1L
// Trimester: 2210
// Member_1: 1211203559 | HO CHUN YAO   | 1211203559@student.mmu.edu.my | 018-7902295
// Member_2: 1191202435 | LUM KAR YU    | 1191202435@student.mmu.edu.my | 010-2084816
// Member_3: 1211203212 | Chang Kai Lok | 1211203212@student.mmu.edu.my | 012-9897002
// Member_4: 1211203346 | Ong Yu Zhe    | 1211203346@student.mmu.edu.my | 017-9289430
// *********************************************************
// Task Distribution
// Member_1:  linked list + file
// Member_2:  linked stack and queue + file
// Member_3:  sorted linked list + file
// Member_4:  binary search tree + file
// *********************************************************
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<numeric>
#include<vector>
using namespace std;

struct ListNode{
    int value;  // the value in this node
    ListNode* next; // to point to the next node
};

//linked list
class LinkedList{
 private:
    //list head pointer
    ListNode* head;
 public:
    //constructor
    LinkedList(){head = nullptr;}//set a new node

    //add the node to the end of the list
    void appendNode(int num){
        ListNode *Node;//to point to a new node
        ListNode *Ptr;//to move through the list
        //allocate a new node and store num there
        Node = new ListNode;
        Node->value =num;
        Node->next = nullptr;

        //If there are no nodes in the list
        //make newNode the first node.
        if(!head)
            head = Node;
        //Otherwise, insert newNode at end
        else{
            //initialize nodePtr to head of list
            Ptr =head;//node *nodePtr =head;
            //find the last node in the list
            while(Ptr->next)
                Ptr = Ptr->next;
            //insert newNode as the last node
            Ptr->next =Node;
        }
    }

    //delete one node only
    void deleteNode(int num){
        ListNode *Ptr;          //traverse the list
        ListNode *preNode;      //point to the previous node
        //if the list is empty , do nothing
        if(!head){
            return;
        }
        //determine if the first node is the one
        if(head->value ==num){
            Ptr=head->next;
            delete head;
            head = Ptr;
        }
        else{
            //initialize Ptr to head of list
            Ptr = head;
            //skip all nodes whose value member is not equal to num
            while(Ptr != nullptr && Ptr->value != num){
                preNode =Ptr;
                Ptr = Ptr->next;
            }
            //if Ptr is not at the end of the list .
            //link the previous node to the node after Ptr, then delete Ptr
            if(Ptr){
                preNode->next=Ptr->next;
                delete Ptr;
            }
        }
    }

    //display value
    void displayList(fstream &output_file)const{
        ListNode *Ptr; //to move through the list

        //position Ptr at the head of the list
        Ptr = head;

        //while Ptr points to a node ,traverse the list
        while(Ptr){
            //display the value in the node
            output_file <<Ptr->value <<" ";
            //move to the next node
            Ptr = Ptr->next;
        }
        output_file<<endl<<endl;
    }

    //determine empty value
    bool isEmpty(){ return head == nullptr;}

    //find maximum value
    int findMax(){
        //initialize temp to head of list
        ListNode *temp = head;
        int max = INT_MIN;
            while(temp != NULL){
                if(max<temp -> value)
                    max = temp -> value;
                temp = temp ->next;
            }
        //return maximum value
        return max;
    }

    //find minimum value
    int findMin(){
        //initialize temp to head of list
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

    //find the value are entering by user
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

//Sorted linked list
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
    /* function to insert a new_node in a list. Note that this function expects a pointer to
    head_ref as this can modify the head of the input linked list (similar to push())*/
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

    void deleteFunc(Node **head, int key){
        // Store head node
        Node* temp = *head;
        Node* prev = NULL;
        // If head node itself holds
        // the key to be deleted
        if (temp != NULL && temp->data == key){
            *head = temp->next; // Changed head
            delete temp;            // free old head
            return;
        }
        // Else Search for the key to be deleted,
        // keep track of the previous node as we
        // need to change 'prev->next' */
        else{
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
    void printList(Node* head,fstream &output_file)
    {
        Node* temp = head;
        while (temp != nullptr) {
            output_file<<temp->data<< " ";
            temp = temp->next;
        }
      output_file<<endl<<endl;
    }
};

//Linked stack
class LinkedStack{
    ListNode* top = NULL;
    int data;
    public:
        // function for add a data value in stack.
        void push( int val ) {
           struct ListNode* newnode = (struct ListNode*) malloc(sizeof(struct ListNode));
           newnode -> value = val;
           newnode -> next = top;
           top = newnode;
        }

        // function for remove the data value from the top stack.
        int pop() {
           if( top == NULL )
           cout<<"\nNo element in stack" << endl;
           else {
                data = top -> value;
              top = top -> next;
           }
          return data;
        }

        // function for show all the data value in the stack.
        void display(fstream &Myfile) {
           struct ListNode* ptr;
           if( top == NULL )
           Myfile<<"\nStack is empty"<<endl;
           else {
              ptr = top;
              while ( ptr != NULL ) {
                 Myfile<<ptr -> value << " ";
                 ptr = ptr -> next;
              }
           }
           Myfile<<endl <<endl;;
        }
};

//binary search tree
class nodeBST{
    int key;
    nodeBST *left, *right;//ptr reference to the node's of left child and right child
    public:

    nodeBST()
    {
        key=0;//initialize key equal to zero
        left=nullptr;//initialize left equal to nullptr
        right=nullptr;//initialize right equal to nullptr
    }
    nodeBST(int value)
    {
        key = value;
        left = right = NULL;
    }
    nodeBST* insertFunc(nodeBST* root, int value)
    {
        if (!root)//return new node if tree is empty
        {
            return new nodeBST(value);
        }
        if (value > root->key)//traverse to the right place and insert node
        {
            root->right = insertFunc(root->right, value);
        }
        else
        {
            root->left = insertFunc(root->left, value);
        }
        return root;
    }
    nodeBST* deleteFunc(nodeBST* root, int key){
        if (root == NULL)// return if tree empty
        return root;
        //find the node to be delete
        if (key < root->key)
            root->left = deleteFunc(root->left, key);
        else if (key > root->key)
            root->right = deleteFunc(root->right, key);
        else {
            //node has no child
            if  (root->left==NULL and root->right==NULL)
                return NULL;

            else if (root->left == NULL){//if the node is with only one child or no child
                nodeBST* temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL){
                nodeBST* temp = root->left;
                free(root);
                return temp;
            }
            nodeBST* temp = minValueNode(root->right);//if the node has two children
            root->key = temp->key;// Place the inorder successor in position of the node to be deleted
            root->right = deleteFunc(root->right, temp->key);// Delete the inorder successor
        }
        return root;
    }

    nodeBST* minValueNode(nodeBST* node){
        nodeBST* current = node;
        while (current && current->left != NULL)//find the leftmost leaf
            current = current->left;

        return current;
    }

void traverseInOrder(nodeBST* root,fstream &output_file){
        if (!root)
        {
            return;
        }
        else{
            traverseInOrder(root->left,output_file);//traverse the left subtree
            output_file<< root->key <<" ";//display current node
            traverseInOrder(root->right,output_file);//traverse the right subtree
        }
    }
};

class LinkedQueue{
 ListNode* front = NULL;
 ListNode* rear = NULL;
 ListNode* temp;
public:
// function for add a data value in queue.
void Insert(int val) {
    if (rear == NULL) {
        rear = (struct ListNode *)malloc(sizeof(struct ListNode));
        rear->next = NULL;
        rear->value = val;
        front = rear;
    }
    else {
        temp=(struct ListNode *)malloc(sizeof(struct ListNode));
        rear->next = temp;
        temp->value = val;
        temp->next = NULL;
        rear = temp;
    }
}

// function for delete the data value from the queue.
int Delete() {
    int return_value;
    temp = front;

    if (front == NULL) {
        cout<<"\nNo element in queue" << endl;
        return 0;
    }
    else if (temp -> next != NULL) {
        temp = temp -> next;
        return_value = front -> value;
        free(front);
        front = temp;
        return return_value;
    }
    else {
        return_value = front -> value;
        free(front);
        front = NULL;
        rear = NULL;
        return return_value;
    }
}

// function for show all the data value in the queue.
void Display(fstream &output) {
    temp = front;
    if ((front == NULL) && (rear == NULL)) {
        output<< "\nQueue is empty\n";
        return;
    }
    while (temp != NULL) {
        output << temp -> value << " ";
        temp = temp -> next;
    }
    output<<endl<<endl;
}
};

void openFile(ifstream& input, string fname)
{
    input.open(fname);
    if(input.is_open())
        cout<<"Successfully opened file"<<endl;
    else{
        cout<<"Failed to open file"<<endl;
        exit(0);
    }
}

void processFile(ifstream& input){
    //declared the class variable name in order to call member function of the class
    LinkedList LT;
    Node *new_node=nullptr, SLT, *head = nullptr;//class of sorted linked list and declared the variable name as SLT.
    LinkedStack ST;
    nodeBST BST, *root = NULL;
    LinkedQueue LQ;

    string data_name;
    string variable_name1,variable_name2,variable_name3,variable_name4,variable_name5;
    int return_value;//for insides the function to return their own value
    int num;
    bool found = false;
    //write data to the file using append mode
    fstream output("output.txt",ios::app);
    string data_structure;
    string structure_name1,structure_name2,operation;
    while(!input.eof()){
        vector<string> tokens;
        string line;
        getline(input, line);
        //split the string line
        stringstream check1(line);
        //find for middle
        string intermediate;
        while(getline(check1, intermediate, ' ')){
            tokens.push_back(intermediate);
        }
        if(tokens.size() == 2){
            //two input
            data_structure = tokens[0];
            structure_name1 = tokens[1];
            if(data_structure == "LinkedList" ){
                output<<structure_name1<<" constructed "<<endl;
                variable_name1 = structure_name1;
            }
            else if(data_structure == "SortedLinkedList"){
                output<<structure_name1<<" constructed "<<endl;
                variable_name2 = structure_name1;
            }
            else if(data_structure == "LinkedStack"){
                output<<structure_name1<<" constructed "<<endl;
                variable_name3 = structure_name1;
            }

            else if(data_structure == "BinarySearchTree"){
                output<<structure_name1<<" constructed"<<endl;
                variable_name4 = structure_name1;
            }
            else if(data_structure == "LinkedQueue"){
                output<<structure_name1<<" constructed"<<endl;
                variable_name5 = structure_name1;
            }

            //for linked list
            if( data_structure == variable_name1 ){
                if(structure_name1 == "min"){
                    output<<LT.findMin()<<endl;
                }
                else if(structure_name1 == "max"){
                    output<<LT.findMax()<<endl;
                }
                else if(structure_name1 == "print")
                    LT.displayList(output);
            }
            //for sorted linked list
            else if( data_structure == variable_name2 ){
                if(structure_name1 == "print")
                    SLT.printList(head,output);
            }
            //for linked stack
            else if( data_structure == variable_name3 ){
                if(structure_name1 == "delete"){
                    return_value=ST.pop();
                    output<<data_structure<<" delete "<<return_value<<endl;
                }
                else if(structure_name1 == "print")
                    ST.display(output);
            }
            //for binary search tree
            else if( data_structure == variable_name4 ){
                if(structure_name1 == "inorder"){
                    BST.traverseInOrder(root,output);
                    output<<endl<<endl;
                }
            }
            //for linked queue
            else if( data_structure == variable_name5 ){
                if(structure_name1 == "delete"){
                    return_value=LQ.Delete();
                    output<<data_structure<<" delete "<<return_value<<endl;
                }
                else if(structure_name1 == "print"){
                    LQ.Display(output);
                }
            }
        }
        if(tokens.size() == 3){
           //three inputs
            structure_name2 = tokens[0];
            operation = tokens[1];
           int num = stoi(tokens[2]);
           if( structure_name2 == variable_name1){
                if(operation == "add"){
                    LT.appendNode(num);
                    output<<structure_name2<<" added "<<num<<endl;
                }
                else if(operation == "delete"){
                    LT.deleteNode(num);
                    output<<structure_name2<<" deleted "<<num<<endl;
                }
                else if(operation == "search"){
                    found=LT.findValue(num);
                    if(found == 1)
                        output <<"Data found"<<endl;
                    else
                        output << "not found"<<endl;
                }
           }
           else if( structure_name2 == variable_name2 ){
                 if(operation == "add"){
                    new_node=SLT.newNode(num);
                    SLT.sortedInsert(&head,new_node);
                    output<<structure_name2<<" added "<<num<<endl;
                }
                else if(operation == "delete"){
                    SLT.deleteFunc(&head,num);
                    output<<structure_name2<<" deleted "<<num<<endl;
                }
           }
           else if(structure_name2 == variable_name3 ){
                if(operation == "add"){
                    ST.push(num);
                    output<<structure_name2<<" added "<<num<<endl;
                }
           }
           else if(structure_name2 == variable_name4 ){
                if(operation == "add"){
                    root=BST.insertFunc(root,num);
                    output<<structure_name2<<" added "<<num<<endl;
                }
                else if(operation == "delete"){
                    root=BST.deleteFunc(root,num);
                    output<<structure_name2<<" delete "<<num<<endl;
                }
           }
           else if(structure_name2 == variable_name5){
                if(operation == "add"){
                    LQ.Insert(num);
                    output<<structure_name2<<" added "<<num<<endl;
                }
           }
    }
  }
}

void file_clear_output(){
    ofstream output;
    output.open("output.txt", ofstream::out | ofstream::trunc);
    output.close();
}

int main()
{
    int choice;
    string whichFile = "input file3.txt";
    //1.open the file
    ifstream input;
    openFile(input,whichFile);
    file_clear_output();
    //2. process the file
    processFile(input);
    //3.close the file
    input.close();
    return 0;
}
