#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class myString {
    private:
        string m_str;
    public:
        myString(string s) {
            m_str=s;   
        }
};

class ReadClass {
    public:
    ReadClass() {
        
    }
    void showClass() {
        ifstream in;
        string line;
        int number=0;
        in.open("main.cpp");
        while(getline(in,line)) {
            if(line.find("class",0)==0) {
                number++;
            }
        }
        cout<<number<<" class in main.cpp"<<endl;
        in.close();
        in.open("main.cpp");
        while(getline(in,line)) {
            if(line.find("class",0)==0) {
                int pos=line.find(" ")+1;
                cout<<line.substr(pos,line.find(" ",pos)-pos)<<endl;
                number++;
            }
        }
    }
    
};

int main() {
    ReadClass rfile;
    rfile.showClass();

    return 0;
}
