#include <stdio.h>
struct array{
    int a[10];
    int size;
    int length;
};
void display(struct array arr){
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.a[i]);
    }
}
void append(struct array *arr,int x){
    arr->a[arr->length++]=x;
}
void insert(struct array *arr,int index,int x){
    for(int i=arr->length;i>index;i--){
        arr->a[i]=arr->a[i-1];
    }
    arr->a[index]=x;
    arr->length++;
}
int main()
{
	struct array arr={{1,2,3,4,5},10,5};
    insert(&arr,4,7);
    
    
    display(arr);
    return 0;
}
