#include <stdio.h>

int main()
{
    char a[]="ABCabcABC";
    int shift=4;
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len;i++,shift++) {
        if(shift==len) {
            shift=0;
        }
        printf("%c",a[shift]);
    }

    return 0;
}


