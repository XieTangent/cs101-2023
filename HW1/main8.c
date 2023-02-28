#include <stdio.h>

int main() {
    char a[]="Hello";
    int len=(char)sizeof(a)/sizeof(a[0]);
    for(int i=0,j=len-2;i<(len-2)/2;i++,j--) {
        int k=a[j];
        a[j]=a[i];
        a[i]=k;
    }
    for(int i=0;i<len;i++) {
        printf("%c",a[i]);
    }

    return 0;
}
