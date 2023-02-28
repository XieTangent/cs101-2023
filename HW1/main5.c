#include <stdio.h>

int get_len(char a[],int len) {
    int j;
    for(int i=0;i<len;i++) {
        if(a[i]==' ') {
            j++;
        }
    }
    return j+1;
}

void sort(int b[],int lenb) {
    for(int i=0;i<lenb;i++) {
        for(int j=i+1;j<lenb;j++) {
            if(b[i]<b[j]) {
                int k=b[i];
                b[i]=b[j];
                b[j]=k;
            }
        }
    }
}

int main() {
    char a[]="-9 8 7 6 5 -4 3 -2 1";
    int i=4;
    int lena=(char)sizeof(a)/sizeof(a[0]);
    int lenb=get_len(a,lena);
    int b[lenb],sign;
    for(int i=0;i<lenb;i++) {
        b[i]=0;
    }
    for(int i=0,j=0;i<lena;i++) {
        if(a[i]==45) {
            sign=-1;
        }else if(57>=a[i]&&a[i]>=48) {
            b[j]=b[j]*10+a[i]-48;
        }else {
            b[j]*=sign;
            sign=1;
            j++;
        }
    }
    sort(b,lenb);
    printf("%d",b[i-1]);

    return 0;
}
