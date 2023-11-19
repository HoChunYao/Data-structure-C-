#include <iostream>
#include <string>
using namespace std;
const int SIZE = 2;
struct Person
{
    char name[50];
    int flavor;
};
class ADTQueue
{
private:
    Person queue[SIZE];
    int head, tail;
public:
    ADTQueue()
    {
        tail = -1;
        head = 0;
    }
    bool empty()
    {
        if(head == tail+1)
        return true;
        else
        return false;
    }
    bool full()
    {
        if(tail == SIZE-1)
        return true;
        else
        return false;
    }
    void append(Person pr)
    {
        if (!full())
        {
            tail++;
            queue[tail] = pr;
        }
        else
        {
            cout<<"Queue is Full"<<endl;
            exit(EXIT_FAILURE);
        }
    }
    Person serve()
    {
        Person pr;
        if(!empty())
        {
            pr = queue[head];
            head++;
            return pr;
        }
        else
        {
            cout<<"Queue is Empty"<<endl;
            exit(EXIT_FAILURE);
        }
    }
};
int main(){
    ADTQueue adt;
    Person ps,p;
    cout<<"Do you know that the flavor of ice-cream can reveal one's personality?"<<endl;

    for(int i=0;i<SIZE;i++){
        cout<<"Enter name: ";
        cin>>ps.name;
        cout<<"Enter favorite flavor:\n(1=chocolate 2=vanilla 3=strawberry 4=mixed flavor)"<<endl;
        cin>>ps.flavor;
        adt.append(ps);
    }
    for(int i=0;i<SIZE;i++){
        p=adt.serve();
        cout<<p.name<<"\t";
        if(p.flavor==1){
            cout<<"Sensitive and often daydreaming about past and future."<<endl;
        }
        else if(p.flavor==2){
            cout<<"Friendly, easygoing and has many friends."<<endl;
        }
        else if(p.flavor==3){
            cout<<"Affectionate, giving, loving and very understanding."<<endl;
        }
        else if(p.flavor==14){
            cout<<"Negotiator and will do anything to avoid open conflict."<<endl;
        }
    }
}
