#include <stdio.h>

int main()
{
    char a[]="A3B2C4A9";
    for(int i=0;i<(char)sizeof(a)/sizeof(a[0]);i+=2) {
        for(int j=0;j<a[i+1]-48;j++) {
            printf("%c",a[i]);
        }
    }

    return 0;
}

