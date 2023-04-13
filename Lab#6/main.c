#include <stdio.h>

int a(int i,int j) {
    if(i==9&&j==9) {
        printf("%d*%d=%d\n",i,j,i*j);
        return 0;
    }else if(j==9) {
        printf("%d*%d=%d\n",i,j,i*j);
        j=1;
        a(i+1,j);
    }else {
        printf("%d*%d=%d ",i,j,i*j);
        a(i,j+1);
    }
}

int main()
{
    a(1,1);

    return 0;
}
