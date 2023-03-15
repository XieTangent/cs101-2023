#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_randomnumber(int n,int num[][7]) {
    srand(time(NULL));
    for(int i=0;i<n;i++) {
        for(int j=0;j<6;j++) {
            num[i][j]=rand()%69+1;
        }
        num[i][6]=rand()%10+1;
    }
}

void if_redundant(int i,int num[][7]) {
    srand(time(NULL));
    for(int m=0;m<7;m++) {
        for(int n=0;n<7;n++) {
            if(num[i][m]==num[i][n] && m!=n && m!=6) {
                num[i][m]=rand()%69+1;
                if_redundant(i,num);
            }else if(num[i][m]==num[i][n]&&m!=n&&m==6) {
                num[i][m]=rand()%10+1;
                if_redundant(i,num);
            }
        }
    }
}

int main()
{
    FILE*fp;
    int n;
    scanf("%d",&n);
    int num[n][7];
    get_randomnumber(n,num);
    time_t t;
    time(&t);
    char *str=ctime(&t);
    if((fp=fopen("lotto.text","w+"))==NULL) {
        printf("Cannot open the file");
        exit(1);
    }
    fprintf(fp,"%s","======== lotto649 ========\n");
    fprintf(fp,"%s%s","==",str);
    for(int i=0;i<n;i++) {
        if_redundant(i,num);
        fprintf(fp,"%s%d%s","[",i+1,"]: ");
        for(int j=0;j<7;j++) {
            if(num[i][j]<10) {
                fprintf(fp,"%d",0);
            }
            fprintf(fp,"%d%s",num[i][j]," ");
        }
        fprintf(fp,"%s","\n");
    }
    for(int i=n;i<5;i++) {
        fprintf(fp,"%s%d%s","[",i+1,"]: -- -- -- -- -- -- --\n");
    }
    fprintf(fp,"%s","======== csie@cgu ========\n");

    return 0;
}
