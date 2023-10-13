#include <stdio.h>
#include <stdlib.h>
struct array{
    int *a;
    int size;
    int length;
};
void pri(struct array arr){
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.a[i]);
    }
}
int main()
{
	int s,n;
    printf("Enter the size:"),scanf("%d",&s);
    printf("Enter no of elements:"),scanf("%d",&n);
    struct array arr;
    arr.size=s;
    arr.length=n;
    arr.a=(int *)malloc(n*sizeof(int));
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr.a[i]);
    }
    pri(arr);
}
