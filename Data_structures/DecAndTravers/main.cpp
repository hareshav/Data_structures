#include <stdio.h>

int main()
{
	int a[5];//garbage value
    int b[5]={1,2,3,4,5};//{1,2,3,4,5}
    int c[5]={1,2};//{1,2,0,0,0}
    int d[5]={0};//{0,0,0,0,0}
    for(int i=0;i<5;i++){
        printf("%d ",d[i]);
    }
}
