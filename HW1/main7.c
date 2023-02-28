#include <stdio.h>

void print_RomeNumber(char a[],int len) {
    for(int i=0;i<len;i++) {
        switch(a[i]) {
            case 49: case 50: case 51:
                for(int j=0;j<a[i]-48;j++) {
                    printf("I");
                }
                printf(" ");
                break;
            case 52:
                printf("IV ");
                break;
            case 53:
                printf("V ");
                break;
            case 54:
                printf("VI ");
                break;
            case 55: case 56:
                printf("V");
                for(int j=0;j<a[i]-53;j++) {
                    printf("I");
                }
                printf(" ");
                break;
            case 57:
                printf("IX ");
                break;
            
        }
        if(a[i]>57||48>a[i]) {
            printf("%c ",a[i]);
        }
    }
}
int main () {
    char a[]="81c8g8u168";
    int len=(char)sizeof(a)/sizeof(a[0]);
    print_RomeNumber(a,len);
  return 0;
}
