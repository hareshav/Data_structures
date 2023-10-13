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
int Delete(struct array *arr,int index){
    if(index<=arr->length){
        int x=arr->a[index];
    
        for(int i=index;i<arr->length-1;i++){
            arr->a[i]=arr->a[i+1];
        }
        arr->length--;
        return x;
    }
    else {
        printf("List index out of range");
        return -1;
    }
}
void swap(struct array *arr,int a,int b){
    int temp=arr->a[a];
    arr->a[a]=arr->a[b];
    arr->a[b]=temp;
}
int lsearch(struct array arr,int key){
    for(int i=0;i<arr.length;i++){
        if(key==arr.a[i]){
            swap(&arr,i,i-1);
            return i;
        }
    }
    return -1;
}
int main()
{
	struct array arr={{1,2,3,4,5},10,5};
    printf("%d\n",lsearch(arr,2));
    display(arr);
    return 0;
}
