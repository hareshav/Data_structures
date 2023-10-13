#include <stdio.h>
#include <stdlib.h>
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
int get(struct array arr,int index){
    if(index>=0&&index<arr.length){
        return arr.a[index];
    }
    return -1;
}
void set(struct array *arr,int index,int x){
    if(index>=0&&index<arr->length){
        arr->a[index]=x;
    }
}
int max(struct array arr){
    int max=0;
    for(int i=0;i<arr.length;i++){
        if(arr.a[i]>max){
            max=arr.a[i];
        }
    }
    return max;
}
int sum(struct array arr){
    int sum=0;
    for(int i=0;i<arr.length;i++){
        sum+=arr.a[i];
    }
    return sum;
}
float avg(struct array arr){
    return sum(arr)/arr.length;
}
void reverse(struct array *arr){
    int *b;
    b=(int *)malloc(arr->length*sizeof(int));
    for(int i=0,j=arr->length-1;i<arr->length;i++,j--){
        b[i]=arr->a[j];
    }
    for(int i=0;i<arr->length;i++){
        arr->a[i]=b[i];
    }
    free(b);
}
void reverse2(struct array *arr){
    for(int i=0,j=arr->length-1;i<j;i++,j--){
        swap(arr,i,j);
    }
}
int main()
{
	struct array arr={{1,2,3,4,5},10,5};
    //printf("%\n",reverse(arr));
    reverse2(&arr);
    display(arr);
    return 0;
}
