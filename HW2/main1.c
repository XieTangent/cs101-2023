#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char transform_char(int num,char *str) {
    if(num<10) {
        str[0]='0';
        str[1]=num+'0';
    }else {
        str[0]=num%10+'0';
        num/=10;
        str[1]=num+'0';
    }
    return *str;
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
    srand(time(NULL));
    int n;
    scanf("%d",&n);
    int num[n][7];
    if((fp=fopen("lotto.text","w+"))==NULL) {
        printf("Cannot open the file");
        exit(1);
    }
    char str5[26]="======== lotto649 =======\n";
    if(fwrite(str5,sizeof(str5),1,fp)!=1) {
            printf("File write error5");
        }
    time_t t;
    time(&t);
    char *str=ctime(&t);
    char str6[26];
    for(int i=0;i<26;i++) {
        str6[i+1]=str[i];
    }
    str6[0]='=';
    if(fwrite(str6,sizeof(str6),1,fp)!=1) {
        printf("File write error6");
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<6;j++) {
            num[i][j]=rand()%69+1;
        }
        num[i][6]=rand()%10+1;
    }
    char str1[3]="   ",str2[3]="  \n",str3[5]="[ ]: ",str4[26]="[ ]: -- -- -- -- -- -- --\n";
    for(int i=0;i<n;i++) {
        if_redundant(i,num);
        str3[1]=i+1+'0';
        if(fwrite(str3,sizeof(str3),1,fp)!=1) {
            printf("File write error3");
        }
        for(int j=0;j<6;j++) {
            transform_char(num[i][j],str1);
            if(fwrite(str1,sizeof(str1),1,fp)!=1) {
                printf("File write error1");
            }
        }
        transform_char(num[i][6],str2);
        if(fwrite(str2,sizeof(str2),1,fp)!=1) {
            printf("File write error2");
        }
    }
    for(int i=n;i<5;i++) {
        str4[1]=i+1+'0';
        if(fwrite(str4,sizeof(str4),1,fp)!=1) {
            printf("File write error4");
        }
    }
    char str7[26]="======== csie@cgu =======\n";
    if(fwrite(str7,sizeof(str7),1,fp)!=1) {
        printf("File write error4");
    }

    return 0;
}

