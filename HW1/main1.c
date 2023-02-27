#include <stdio.h>

void encoding(char a[],int len) {
    int num=1;
    for(int i=0;i<len;i++) {
        if(a[i]==a[i+1]) {
            num+=1;
        }else {
            printf("%c%d",a[i],num);
            num=1;
        }
    }
}
int main() {
    char a[]="AABBBCCCCDDD";
    int len=(char)sizeof(a)/sizeof(char);
    encoding(a,len);

    return 0;
}
