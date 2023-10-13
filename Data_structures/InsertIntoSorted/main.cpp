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
void InSorted(struct array *arr,int x){
    int i=arr->length-1;
    while(x<arr->a[i]){
       arr->a[i+1]=arr->a[i];
       i--;
    }
    arr->length++;
    arr->a[i+1]=x;
}
int sorted(struct array arr){
    for(int i=0;i<arr.length-1;i++){
        if(arr.a[i]>arr.a[i+1]){
            return 0;
        }
    }
    return 1;
}
void negleftshift(struct array *arr){
    int i=0;
    int j=arr->length-1;
    while(i<j){
        while(arr->a[i]<0){i++;}
        while(arr->a[j]>=0){j--;}
        if(i<j)swap(arr,i,j);
        printf("%d %d\n",i,j);
    }
}
struct array* mergearray(struct array arr1,struct array arr2){
    int i=0,j=0,k=0;
    struct array *arr3=(struct array*)malloc(sizeof(struct array));
    while(i<arr1.length&&j<arr2.length){
        if(arr1.a[i]>arr2.a[j]){
            arr3->a[k++]=arr2.a[j++];
        }
        else {
            arr3->a[k++]=arr1.a[i++];
        }
    }
    for(;i<arr1.length;i++){
        arr3->a[k++]=arr1.a[i];
    }
    for(;j<arr2.length;j++){
        arr3->a[k++]=arr2.a[j];
    }
    arr3->length=arr1.length+arr2.length;
    arr3->size=arr1.size+arr2.size;
    return arr3;
}
struct array* unionsort(struct array arr1,struct array arr2){
    int i=0,j=0,k=0;
    struct array *arr3=(struct array*)malloc(sizeof(struct array));
    while(i<arr1.length&&j<arr2.length){
        if(arr1.a[i]>arr2.a[j]){
            arr3->a[k++]=arr2.a[j++];
        }
        else if(arr1.a[i]<arr2.a[j]){
            arr3->a[k++]=arr1.a[i++];
        }
        else{
            j++;
            arr3->a[k++]=arr1.a[i++];
        }
    }
    for(;j<arr2.length;j++){
        arr3->a[k++]=arr2.a[j];
    }
    for(;i<arr1.length;i++){
        arr3->a[k++]=arr1.a[i];
    }
    
    arr3->length=k;
    arr3->size=10;
    return arr3;
}
struct array* intsort(struct array arr1,struct array arr2){
    int i=0,j=0,k=0;
    struct array *arr3=(struct array*)malloc(sizeof(struct array));
    while(i<arr1.length&&j<arr2.length){
        if(arr1.a[i]==arr2.a[j]){
            arr3->a[k++]=arr1.a[i++];
            j++;
        }
        else if(arr1.a[i]>arr2.a[j]){
            j++;
        }
        else{i++;}
    }
    
    
    arr3->length=k;
    arr3->size=10;
    return arr3;
}
struct array* difsort(struct array arr1,struct array arr2){
    int i=0,j=0,k=0;
    struct array *arr3=(struct array*)malloc(sizeof(struct array));
    while(i<arr1.length&&j<arr2.length){
         if(arr1.a[i]>arr2.a[j]){
            arr3->a[k++]=arr1.a[i++];
            j++;
        }
        else if(arr1.a[i]<arr2.a[j]){
            arr3->a[k++]=arr1.a[i++];
        }
        else{
            i++;
            j++;
        }
    }
    
    for(;j<arr2.length;j++){
        arr3->a[k++]=arr2.a[j];
    }
    for(;i<arr1.length;i++){
        arr3->a[k++]=arr1.a[i];
    }
    arr3->length=k;
    arr3->size=10;
    return arr3;
}
int main()
{
	struct array arr1={{2,3,5,8,10},10,5};
    struct array arr2={{1,3,5,7,8},10,5};
    struct array *arr3=difsort(arr1,arr2);;
    //printf("%d\n",sorted(arr));
    
    display(*arr3);
    return 0;
}
