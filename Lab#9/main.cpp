#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ReplaceMyString {
    public:
    ReplaceMyString() {
        
    }
    void replaceString(string oldstr,string newstr) {
        fstream in("main.cpp");
        ofstream out;
        int pos=0;
        in.open("main.cpp");
        out.open("rmain.cpp");
        string str((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
        while(1==1) {
            pos=str.find(oldstr,pos);
            if(pos==-1) {
                pos=0;
                break;
            }
            str.replace(pos,oldstr.length(),newstr);
            pos+=newstr.length();
        }
        out<<str<<endl;
        in.close();
        out.close();
    }
};

int main() {
    ReplaceMyString my;
    my.replaceString("IU","IU is best");

    return 0;
}
