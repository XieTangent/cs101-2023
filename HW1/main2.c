#include <stdio.h>

void decode(char a[],int len) {
    for(int i=0;i<len;i+=2) {
        for(int j=0;j<a[i+1]-48;j++) {
            printf("%c",a[i]);
        }
    }
}

int main() {
    char a[]="A3B2C4A9";
    int len=(char)sizeof(a)/sizeof(a[0]);
    decode(a, len);

    return 0;
}
