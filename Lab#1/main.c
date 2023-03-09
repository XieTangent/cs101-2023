#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fp;
    int a[]={1,2,3};
    int b[3];
    if((fp=fopen("a.bin","wb+"))==NULL) {
        printf("Cannot open the file");
        exit(1);
    }
    if(fwrite(a,sizeof(a),1,fp)!=1) {
        printf("File write error");
    }
    fseek(fp,0,SEEK_SET);
    if(fread(b,sizeof(b),1,fp)!=1) {
        printf("File read error");
    }
    for(int i=0;i<3;i++) {
        printf("%d",b[i]);
    }
    

    return 0;
}
