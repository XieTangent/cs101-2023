#include <stdio.h>

void print_integer(char a[],int len) {
    for(int i=0;i<len;i++) {
        if(a[i]==45) {
            printf("-");
        } else if(9>=a[i]-48 && a[i]>=1) {
            printf("%c",a[i]);
        }
    }
    printf("\n");
}

int main()
{
    char a[]="-99acbc";
    char b[]="99acbc";
    char c[]="ac-99bc";
    print_integer(a,(char)sizeof(a)/sizeof(a[0]));
    print_integer(b,(char)sizeof(b)/sizeof(b[0]));
    print_integer(c,(char)sizeof(c)/sizeof(c[0]));

    return 0;
}
