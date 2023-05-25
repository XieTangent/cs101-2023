#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class ReplaceMyString {
    public:
    ReplaceMyString() {
        
    }
    void replaceString(string m,string n) {
        ifstream in;
        ofstream out;
        string read;
        in.open("main.cpp");
        out.open("rmain.cpp");
        while(!in.eof()) {
            in>>read;
            char *k=strstr(read,m);
            if(k!=NULL) {
                read=n;
            }
            out<<read<<endl;
        }
        in.close();
        out.close();
    }
};

int main()
{
    ReplaceMyString my;
    my.replaceString("IU","IU is best");

    return 0;
}
