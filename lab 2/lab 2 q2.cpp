#include <iostream>
using namespace std;

class box{
public :
    float length,breadth,height,volume;
    void calculate(){
    volume = length * breadth * height;
    }
};

int main(){
    box B1,B2;
    B1.length = 5.0;B1.breadth = 6.0;B1.height=7.0;
    B2.length = 10.0;B2.breadth = 12.0;B2.height=13.0;
    B1.calculate();
    cout<<"Volume of Box 1 : "<<B1.volume<<endl;
    B2.calculate();
    cout<<"Volume of Box 2 : "<<B2.volume<<endl;

}
