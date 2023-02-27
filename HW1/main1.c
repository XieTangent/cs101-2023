#include <stdio.h>

int main()
{
    char a[]="AABBBCCCCDDD";
    int num=1;
    for(int i=0;i<(char)sizeof(a)/sizeof(char);i++) {
        if(a[i]==a[i+1]) {
            num+=1;
        }else {
            printf("%c%d",a[i],num);
            num=1;
        }
    }

    return 0;
}
