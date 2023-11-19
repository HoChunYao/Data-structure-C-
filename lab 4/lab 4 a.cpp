//set a struct in a queue line
#include <iostream>
#include <string>
using namespace std;
const int SIZE = 5;

struct Person{
    char name[50];
    int flavor;
};

class ADTQueue{
private:
    Person queue[SIZE];
    int head, tail;
public:
    ADTQueue(){
        tail = -1;
        head = 0;
    }
    bool empty(){
        if(head == tail+1)
        return true;
        else
        return false;
    }
    bool full(){
        if(tail == SIZE-1)
        return true;
        else
        return false;
    }
    void append(Person pr){
        if (!full()){
            tail++;
            queue[tail] = pr;
        }
        else{
            cout<<"Queue is Full"<<endl;
            exit(EXIT_FAILURE);
        }
    }
    Person serve(){
        Person pr;
        if(!empty()){
        pr = queue[head];
        head++;
        return pr;
        }
        else{
        cout<<"Queue is Empty"<<endl;
        exit(EXIT_FAILURE);
        }
    }
};

int main(){
    Person p;
    ADTQueue q;

    cout<<"Do you know that the flavor of ice-cream can reveal one's personality"<<endl<<endl;

   for(int x=0;x<2;x++){
    cout<<"Enter name : ";cin>>p.name;
    cout<<"Enter favorite flavor : \n "<<
    "(1=chocolate 2=vanilla 3=strawberry 4=mixed flavor)"<<endl;cin>>p.flavor;
    q.append(p);
   }

    for(int y=0;y<2;y++){
        p=q.serve();
        cout<<p.name<<"\t";
        if( p.flavor == 1){
            cout<<"Sensitive and often day dreaming about past and future"<<endl;
        }
        else if(p.flavor == 2){
            cout<<"Friendly, easy going and has many friends."<<endl;
        }
        else if(p.flavor == 3){
            cout<<"Affectionate, giving, loving and very understanding."<<endl;
        }
        else if(p.flavor == 4){
            cout<<"Negotiator and will do anything to avoid open conflict."<<endl;
        }
    }
}
