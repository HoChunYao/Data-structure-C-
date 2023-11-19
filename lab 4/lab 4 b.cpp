#include <iostream>
#include <string>
using namespace std;
const int SIZE = 10;

class ADTQueue
{
    private:
        int queue[SIZE];
        int head, tail;
        int count = 0;
    public:
        ADTQueue()
        {
            tail = -1;
            head = 0;
        }
        bool empty()
        {
            if(count == 0)
            return true;
            else
            return false;
        }
        bool full()
        {
            if(count == SIZE)
            return true;
            else
            return false;
        }
        void append(int num)
        {
            if (!full())
            {
                tail = (tail+1) % SIZE;
                queue[tail] = num;
                ++count;
            }
            else
            {
                cout<<"Error: queue is full"<<endl;
            }
        }
        int serve()
        {
            int num;
            if(!empty())
            {
                num = queue[head];
                head = (head+1) % SIZE;
                --count;
                return num;
            }
            else
            {
                cout<<"Error: queue is empty"<<endl;
                exit(1);
            }
        }
};

int main(){
    ADTQueue q;
    int x = 2,y = 4,z = 6;
    q.append(8);
    q.append(x-y);
    q.append(z);
    y += q.serve();
    q.append(x+z);
    z = q.serve() - 4;
    q.append(z);
    q.append(3);
    x -= q.serve();
    q.append(x);
    cout<< "Elements in the queue are: "<<endl;
    while(!q.empty()){
        cout<<q.serve()<<endl;
    }
}
