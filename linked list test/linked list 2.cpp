// *********************************************************
// Program: YOUR_FILENAME.cpp
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
// Member_2:  linked stack and queue
// Member_3:  sorted linked list + file
// Member_4:  binary search tree + file
// *********************************************************

#include<iostream>
#include<fstream>
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
            cout<<Ptr ->value <<" ";
            output_file <<Ptr->value <<" ";
            //move to the next node
            Ptr = Ptr->next;
        }
        output_file<<endl;
        cout<<endl;
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

//sorted linked list
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
    void printList(Node* head,fstream &output_file)
    {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            output_file<<temp->data<< " ";
            temp = temp->next;
        }
      output_file<<endl;
      cout<<endl;
    }
};

//Linked stack and queue
class LinkedStack{
    struct ListNode* top = NULL;
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
              cout << "\nThe delete value is : "<< data << endl;
              top = top -> next;
           }
          return data;
        }

        // function for show all the data value in the stack.
        void display(fstream &Myfile) {
           struct ListNode* ptr;
           if( top == NULL )
           cout<<"\nStack is empty, choose[1] to add value to the stack.";
           else {
              ptr = top;
              cout<<"\nStack elements are: ";
              while ( ptr != NULL ) {
                 cout << ptr -> value << " ";
                 Myfile<<ptr -> value << " ";
                 ptr = ptr -> next;
              }
           }
           Myfile<<endl;
           cout << endl;
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
    nodeBST* deleteFunc(nodeBST* root, int key)
    {
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

            else if (root->left == NULL)//if the node is with only one child or no child
            {
                nodeBST* temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
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
    nodeBST* minValueNode(nodeBST* node)
    {
        nodeBST* current = node;
        while (current && current->left != NULL)//find the leftmost leaf
            current = current->left;

        return current;
    }

    void traverseInOrder(nodeBST* root,fstream &output_file)
    {
        if (!root)
        {
            return;
        }
        else{
            traverseInOrder(root->left,output_file);//traverse the left subtree
            output_file<< root->key <<" ";
            cout << root->key <<" ";//display current node
            traverseInOrder(root->right,output_file);//traverse the right subtree
        }
    }
};

//input and output file
class file{
private:
    LinkedList LS;
    LinkedStack ST;
    Node *new_node=nullptr,node,*head = nullptr;
    nodeBST BST, *root = NULL;
    int choice,num,name;
    char conti;
    string myText;
    string name_of_variable;
    bool found = false;
public:
    void File_of_linkedList(){
        // Create and open a text file
        fstream inputFile("input.txt",ios::app);
        fstream MyFile("Output.txt",ios::app);
        ifstream MyReadFile("Output.txt");
        system("CLS");
        cout<<" Name of variable : "<<endl;
        cout<<" 1. list "<<endl;
        cout<<" 2. lst "<<endl;
        cout<<" 3. other "<<endl;
        cout<<" Enter your preference name number : ";cin>>name;
        switch(name){
        case 1:
            name_of_variable = "list";
            break;
        case 2:
            name_of_variable = "lst";
            break;
        case 3:
            cout<<" Enter your preference variable : ";cin>>name_of_variable;
            break;
        }

        inputFile<<"Linkedlist "<<name_of_variable<<endl;
        MyFile<<name_of_variable<<" constructed"<<endl;

        do
        {
            system("CLS");
            cout<<"1. add\n2. delete\n3. Find max\n4. Find min\n5. Search\n6. Print the list\n7. Main page"<<endl;
            cout<<"Insert choice(1,2,3,4,5,6,7) : ";
            cin>>choice;
            if(choice==1)
            {
                cout<<"Enter the number you wish to add : ";
                cin>>num;
                LS.appendNode(num);
                inputFile <<name_of_variable<< " add "<<num<<endl;
                MyFile <<name_of_variable<<" added "<<num<<endl;
            }
            else if(choice==2)
            {
                cout<<"Enter the number you wish to delete : ";
                cin>>num;
                LS.deleteNode(num);
                inputFile <<name_of_variable<< " deleted "<<num<<endl;
                MyFile << name_of_variable<<" deleted "<<num<<endl;
            }
            else if(choice == 3){
                cout<<"Find the maximum value that are enter by yourself"<<endl;
                cout<<"The maximum value is : "<<LS.findMax()<<endl;
                inputFile <<name_of_variable<< " max"<<endl;
                MyFile <<name_of_variable<< " max "<<LS.findMax()<<endl;
                system ("PAUSE");
            }
            else if(choice == 4){
                cout<<"Find the minimum value that are enter by yourself"<<endl;
                cout<<"The minimum value is : "<<LS.findMin()<<endl;
                inputFile <<name_of_variable<< " min"<<endl;
                MyFile <<name_of_variable<< " mix "<<LS.findMin()<<endl;
                system ("PAUSE");
            }
            else if(choice == 5){
                cout<<"Enter the number you want to search : ";
                cin>>num;
                found=LS.findValue(num);
                inputFile<<name_of_variable<<" search "<<num<<endl;
                if(found == 1){
                    cout<<"data found"<<endl;
                    MyFile <<"Data found"<<endl;
                }
                else{
                    cout<<"Data not found"<<endl;
                    MyFile << "not found"<<endl;
                }
                system ("PAUSE");
            }
            else if(choice == 6){
                cout<<"List will be print "<<endl;
                inputFile<<name_of_variable<<" print"<<endl;
                LS.displayList(MyFile);
                system ("PAUSE");
            }
            else if(choice == 7){
                cout<<"Back to the main page"<<endl;
            }
            else
            {
                cout<<"Invalid Choice!"<<endl;
                exit(0);
            }
        }while(choice != 7);
        system("CLS");
        MyFile.close();

        while (getline (MyReadFile, myText)) {
        // Output the text from the file
            cout <<myText<<endl;
        }
        system ("PAUSE");
        MyReadFile.close();
    }

    void File_of_sortedLinkedList(){
        // Create and open a text file
        fstream inputFile("input.txt",ios::app);
        fstream MyFile("Output.txt",ios::app);
        ifstream MyReadFile("Output.txt");
        system("CLS");
        cout<<" Name of variable : "<<endl;
        cout<<" 1. sortedList "<<endl;
        cout<<" 2. sll "<<endl;
        cout<<" 3. other "<<endl;
        cout<<" Enter your preference name number : ";cin>>name;
        switch(name){
        case 1:
            name_of_variable = "sortedList";
            break;
        case 2:
            name_of_variable = "sll";
            break;
        case 3:
            cout<<" Enter your preference variable : ";cin>>name_of_variable;
            break;
        }

        inputFile<<"SortedLinkedList "<<name_of_variable<<endl;
        MyFile<<name_of_variable<<" constructed"<<endl;
        do
        {
            system("CLS");
            cout<<"1. add\n2. delete \n3. Print\n4. Main Page"<<endl;
            cout<<"Insert choice(1,2,3,4) : ";
            cin>>choice;
            if(choice==1)
            {
                cout<<"Enter the number you wish to add : ";
                cin>>num;
                new_node=node.newNode(num);
                node.sortedInsert(&head,new_node);
                inputFile<<name_of_variable<<" add "<<num<<endl;
                MyFile <<name_of_variable<<" added "<<num<<endl;
            }
            else if(choice==2)
            {
                cout<<"Enter the number you wish to delete : ";
                cin>>num;
                node.deleteFunc(&head,num);
                inputFile<<name_of_variable<<" delete "<<num<<endl;
                MyFile   <<name_of_variable<<" deleted "<<num<<endl;
            }
            else if(choice == 3){
                inputFile<<name_of_variable<<" print "<<endl;
                node.printList(head,MyFile);
                system ("PAUSE");
            }
            else if(choice == 4){
                system("CLS");
                cout<<"Back to the main page"<<endl;
            }
            else
            {
                system("CLS");
                cout<<"Invalid Choice!"<<endl;
                exit(0);
            }
        }while(choice != 4);

        MyFile.close();

        while (getline (MyReadFile, myText)) {
        // Output the text from the file
            cout <<myText<<endl;
        }
        system ("PAUSE");
        MyReadFile.close();
    }

    void File_of_linkedStack(){
        fstream inputFile("input.txt",ios::app);
        fstream MyFile("Output.txt",ios::app);
        ifstream MyReadFile("Output.txt");
        system("CLS");
        cout<<" Name of variable : "<<endl;
        cout<<" 1. stack "<<endl;
        cout<<" 2. stk "<<endl;
        cout<<" 3. other "<<endl;
        cout<<" Enter your preference name number : ";cin>>name;
        switch(name){
        case 1:
            name_of_variable = "stack";
            break;
        case 2:
            name_of_variable = "stk";
            break;
        case 3:
            cout<<" Enter your preference variable : ";cin>>name_of_variable;
            break;
        }

        inputFile<<"LinkedStack  "<<name_of_variable<<endl;
        MyFile<<name_of_variable<<" constructed"<<endl;
        do
        {
            system("CLS");
            cout<<"1. add\n2. delete \n3. Print\n4. Main Page"<<endl;
            cout<<"Insert choice(1,2,3,4) : ";
            cin>>choice;
            if(choice==1)
            {
                cout<<"Enter the number you wish to add : ";
                cin>>num;
                ST.push(num);
                inputFile<<name_of_variable<<" add "<<num<<endl;
                MyFile <<name_of_variable<<" added "<<num<<endl;
            }
            else if(choice==2)
            {
                num = ST.pop();
                cout<<"The number have been deleted is : "<<num<<endl;;
                inputFile<<name_of_variable<<" delete "<<num<<endl;
                MyFile   <<name_of_variable<<" deleted "<<num<<endl;
                system("PAUSE");
            }
            else if(choice == 3){
                inputFile<<name_of_variable<<" print "<<endl;
                ST.display(MyFile);
                system ("PAUSE");
            }
            else if(choice == 4){
                system("CLS");
                cout<<"Back to the main page"<<endl;
            }
            else
            {
                system("CLS");
                cout<<"Invalid Choice!"<<endl;
                exit(0);
            }
        }while(choice != 4);

        MyFile.close();

        while (getline (MyReadFile, myText)) {
        // Output the text from the file
            cout <<myText<<endl;
        }
        system ("PAUSE");
        MyReadFile.close();
    }

    void File_of_BST(){
        fstream inputFile("input.txt",ios::app);
        fstream MyFile("Output.txt",ios::app);
        ifstream MyReadFile("Output.txt");
        system("CLS");
        cout<<" Name of variable : "<<endl;
        cout<<" 1. bst"<<endl;
        cout<<" 2. binSearchTree "<<endl;
        cout<<" 3. other "<<endl;
        cout<<" Enter your preference name number : ";
        cin>>name;
        switch(name){
        case 1:
            name_of_variable = "bst";
            break;
        case 2:
            name_of_variable = "binSearchTree";
            break;
        case 3:
            cout<<" Enter your preference variable : ";cin>>name_of_variable;
            break;
        }
        inputFile<<"Binary Search Tree "<<name_of_variable<<endl;
        MyFile<<name_of_variable<<" constructed"<<endl;
        do
        {
            system("CLS");
            cout<<"1. add\n2. delete\n3. Inorder\n4. Main Page"<<endl;
            cout<<"Insert choice(1,2,3) : ";cin>>choice;
            if(choice==1)
            {
                cout<<"Enter the number you wish to add : ";
                cin>>num;
                root=BST.insertFunc(root, num);
                inputFile<<name_of_variable<<" add "<<num<<endl;
                MyFile << name_of_variable<<" added "<<num<<endl;
                system("PAUSE");
            }
            else if(choice==2)
            {
                cout<<"Enter the number you wish to delete : ";
                cin>>num;
                root=BST.deleteFunc(root, num);
                inputFile<<name_of_variable<<" delete "<<num<<endl;
                MyFile << name_of_variable<<" deleted "<<num<<endl;
                system("PAUSE");
            }
            else if(choice==3)
            {
                cout<<"\nThe sorted binary search tree is  "<< endl;
                cout<<"------------------------------------"<<endl;
                BST.traverseInOrder(root,MyFile);
                cout<<"\n------------------------------------"<<endl;
                inputFile<<name_of_variable<<" Inorder "<<endl;
                cout<<endl;
                MyFile<<endl;
                system("PAUSE");

            }
            else if(choice == 4)
            {
                system("CLS");
                cout<<"Back to the main page"<<endl;
            }
            else
            {
                system("CLS");
                cout<<"Invalid Choice!"<<endl;
                exit(0);
            }


        }while(choice != 4);
        MyFile.close();
        while (getline (MyReadFile, myText)) {
        // Output the text from the file
            cout <<myText<<endl;
        }
        system ("PAUSE");
        MyReadFile.close();
    }

    void Clear_file(){
        ofstream input;
        input.open("input.txt", ofstream::out | ofstream::trunc);
        input.close();
        ofstream output;
        output.open("Output.txt", ofstream::out | ofstream::trunc);
        output.close();
    }
};



int main(){
    file F;
    int choice;
    F.Clear_file();
    do{
        system("CLS");
        cout<<" What data structure program you want to choice "<<endl;
        cout<<" 1. Linked list"<<endl;
        cout<<" 2. Sorted linked list "<<endl;
        cout<<" 3. Linked stack "<<endl;
        cout<<" 4. Binary search tree "<<endl;
        cout<<" 5. Clear file data "<<endl;
        cout<<" 6. Exit the system "<<endl;
        cout<<" Enter your choice : "; cin >> choice;

        if(choice == 1)
            F.File_of_linkedList();
        else if(choice == 2)
            F.File_of_sortedLinkedList();
        else if(choice == 3)
            F.File_of_linkedStack();
        else if(choice == 4)
            F.File_of_BST();
        else if(choice == 5){
            system("CLS");
            cout<<" Clearing the data of file ...."<<endl;
            system("PAUSE");
            system("CLS");
            F.Clear_file();
            cout<<" File cleared "<<endl;
            system("PAUSE");
        }
        else if(choice == 6){
            cout<<" \n Thank you for using our system "<<endl;
            exit(0);
        }
        else{
            cout<<" Invalid Choice!"<<endl;
            cout<<" Please try again"<<endl;
            exit(0);
        }
    }while(choice != 6);
}


