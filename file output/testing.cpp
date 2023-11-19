#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class file{
private:
    int num_of_line = 0;
public:
    int Line(){
        ifstream file;
        file.open("input file.txt");
        if(file.is_open()){
            string line;
            while(getline(file, line))
                num_of_line = num_of_line + 1;
        }
        else{
            cout<<"Unable to open the file."<<endl;
            num_of_line = 0;
        }
        file.close();

        return num_of_line;
    }


    void read_data(){
        ifstream myfile;
        myfile.open("input file.txt");
        string myline;

        if ( myfile.is_open() ) {
            while ( myfile ){
                //getline (myfile, myline);
                myfile>>myline;
                cout << myline <<  '\n';
            }
        }
    }

};

int main(){
    file f;
    cout<<f.Line()<<endl;
    f.read_data();
}


