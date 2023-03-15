#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE*fp1;
    FILE*fp2;
    if((fp1=fopen("main2.c","r+"))==NULL) {
        printf("Fail1");
        exit(1);
    }
    fseek(fp1,0,SEEK_END);
    int size=ftell(fp1);
    fseek(fp1,0,SEEK_SET);
    char read_arr[size];
    if((fread(read_arr,sizeof(read_arr),1,fp1))!=1) {
        printf("Fail2");
    }
    if((fp2=fopen("main2.text","w+"))==NULL) {
        printf("Fail");
    }
    fprintf(fp2,"%s",read_arr);

    return 0;
}
