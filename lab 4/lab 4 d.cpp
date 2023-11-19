#include <iostream>
#include <string>
#include <cmath>
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
ADTQueue que;
int x = 3;
int y = 6;
que.append(8);
que.append(x-y);
que.append(y);
y %= que.serve();
que.append(x);
y = que.serve( ) * 2;
que.append(y);
que.append(3);
x *= que.serve( );
que.append(x);
que.append(pow(y,2));
cout<<"Elements in the queue are: \n";
while(!que.empty( ))
{
cout<<que.serve( )*5<<endl;
}
cout<<"x="<<x<<endl;
cout<<"y="<<y<<endl;
}
