#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[3][4]={{1,2,3,4},{4,5,6,7},{1,23,4,5}}; 
    
    int *b[3];
    int **c;
    b[0]=(int *)malloc(sizeof(int)*4);
    b[1]=(int *)malloc(sizeof(int)*4);
    b[2]=(int *)malloc(sizeof(int)*4);
    
    c=(int**)malloc(sizeof(int *)*3);
    c[0]=(int *)malloc(sizeof(int)*4);
    c[1]=(int *)malloc(sizeof(int)*4);
    c[2]=(int *)malloc(sizeof(int)*4);
    for(int i=0;i<3;i++){
        for (int j=0;j<4;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}
