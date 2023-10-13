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
int binary(struct array arr,int key)
{
    int l=0,h=arr.length-1,m;
    while(l<=h){
        m=(l+h)/2;
        if(key==arr.a[m]){
            return m;
        }
        else if(key<arr.a[m]){
            h=m-1;
        }
        else{
            l=m+1;
        }
    }
    return -1;
}
int rbinary(struct array arr,int l,int h,int key){
    if(l<=h){
        int mid=(l+h)/2;
        if(key==arr.a[mid]){
            return mid;
        }
        if(key<arr.a[mid]){
            return rbinary(arr,l,mid-1,key);
        }
        if(key>arr.a[mid]){
            return rbinary(arr,mid+1,h,key);
        }
    }
    else return -1;
}
int main()
{
	struct array arr={{1,1},10,2};
    
    printf("%d\n",binary(arr,5))
    display(arr);
    return 0;
}
