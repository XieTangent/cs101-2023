#include <stdio.h>

replace_all(char* str,char oldchar,char newchar) {
    while(*str!=' ') {
        if(*str==oldchar) {
            *str=newchar;
        }
        str++;
    }
}

int main() {
    char str[100],oldchar='a',newchar='A';
    printf("Enter any string: ");
    scanf("%s",str);
    printf("\nString before replacing: \n%s",str);
    replace_all(str,oldchar,newchar);
    printf("\n\nString after replacing %c  with %c : \n%s",oldchar,newchar,str);

    return 0;
}
