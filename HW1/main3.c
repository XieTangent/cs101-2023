#include <stdio.h>

void moveleft(char a[],int len,int shift) {
    for(int i=0;i<len;i++,shift++) {
        if(shift==len) {
            shift=0;
        }
        printf("%c",a[shift]);
    }
}

int main() {
    char a[]="ABCabcABC";
    int shift=4;
    int len=sizeof(a)/sizeof(a[0]);
    moveleft(a,len,shift);

    return 0;
}
