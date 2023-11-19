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
        void enqueue(int num)
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
        int dequeue()
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
int main()
{
    int m =6,n=8;
    ADTQueue q;
    q.enqueue(m);
    q.enqueue(n);
    n += q.dequeue();
    q.enqueue(n);
    q.enqueue(m+n);
if(q.dequeue() >= m)
    m = q.dequeue();
    q.enqueue(m);
    q.enqueue(12);
if(q.dequeue() < m)
    m =q.dequeue();
        cout<< "Elements in the queue are: "<<endl;
    while(!q.empty()){
        cout<<q.dequeue()<<endl;
    }
    cout<<"m="<<m<<endl;
    cout<<"n="<<n<<endl;

}
