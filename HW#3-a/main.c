#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void hanoi(int n, char A, char B, char C) {
    FILE*fp;
    fp=fopen("hanoi,text","a+");
    if(n == 1) {
        fprintf(fp,"%s %d %s %c %s %c %s","Move P",n, " from ",A," to ",C,"\n");
        fclose(fp);
    }else {
        hanoi(n-1, A, C, B);
        fprintf(fp,"%s %d %s %c %s %c %s","Move P",n, " from ",A," to ",C,"\n");
        fclose(fp);
        hanoi(n-1, B, A, C);
    }
}


int main() {
    FILE*fp;
    fp=fopen("hanoi,text","a+");
    int n;
    printf("請輸入盤數：");
    scanf("%d",&n);
    time_t t1,t2;
    time(&t1);
    fprintf(fp,"%s",ctime(&t1));
    fclose(fp);
    hanoi(n,'A','B','C');
    fp=fopen("hanoi,text","a+");
    time(&t2);
    fprintf(fp,"%s%s",ctime(&t2),"\n");
    fclose(fp);
    return 0;
} 
