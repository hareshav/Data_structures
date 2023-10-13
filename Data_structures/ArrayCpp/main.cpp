#include <stdio.h>
#include <stdlib.h>
class Array
{private:
     int *A;
     int size;
     int length;
     void swap(int *x,int *y);
     A=(int *)malloc(size*sizeof(int));
     
public:
    void Display();
    void Insert(int index,int x);
    void Append(int x);
    int Delete(int index);
    void swap(int *x,int *y);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    void Set(int index,int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    Array* Merge(Array arr2);
};
void Array::Display()
{
     int i;
     printf("\nElements are\n");
     for(i=0;i<length;i++)
     printf("%d ",A[i]);
}
void Array::Append(int x)
{
     if(length<size)
     A[length++]=x;

}
void Array::Insert(int index,int x)
{
     int i;
     if(index>=0 && index <=length)
     {
     for(i=length;i>index;i--)
     A[i]=A[i-1];
     A[index]=x;
     length++;

    }
}
int Delete(int index)
{
     int x=0;
     int i;

     if(index>=0 && index<length)
     {
         x=[index];
         for(i=index;i<length-1;i++)
             A[i]=A[i+1];
         length--;
         return x;
     }

     return 0;
}
void swap(int *x,int *y)
{
     int temp;
     temp=*x;
     *x=*y;
     *y=temp;
}
int LinearSearch(int key)
{
     int i;
     for(i=0;i<length;i++)
     {
         if(key==A[i])
         {
            swap(&A[i],&A[0]);
            return i;
         }
     }
     return -1;
}
int BinarySearch(int key)
{
     int l,mid,h;
     l=0;
     h=length-1;

     while(l<=h)
     {
        mid=(l+h)/2;
        if(key==A[mid])
            return mid;
        else if(key<A[mid])
            h=mid-1;
        else
            l=mid+1;
     }
     return -1;
}
/*int RBinSearch(int a[],int l,int h,int key)
{
 int mid;

 if(l<=h)
 {
 mid=(l+h)/2;
 if(key==a[mid])
 return mid;
 else if(key<a[mid])
 return RBinSearch(a,l,mid-1,key);
 else
 return RBinSearch(a,mid+1,h,key);
 }
 return -1;
}*/
int Get(int index)
{
     if(index>=0 && index<length)
        return A[index];
     return -1;
}
void Set(int index,int x)
{
     if(index>=0 && index<length)
        A[index]=x;
}
int Max()
{
     int max=A[0];
     int i;
     for(i=1;i<length;i++)
     {
         if(A[i]>max)
         max=A[i];
     }
     return max;
}
int Min()
{
     int min=A[0];
     int i;
     for(i=1;i<length;i++)
     {
         if(A[i]<min)
         min=A[i];
     }
     return min;
}
int Sum()
{
     int s=0;
     int i;
     for(i=0;i<length;i++)
     s+=A[i];

     return s;
}
float Avg()
{
    return (float)Sum(arr)/length;
}
void Reverse()
{
     int *B;
     int i,j;

     B=(int *)malloc(length*sizeof(int));
     for(i=length-1,j=0;i>=0;i--,j++)
     B[j]=A[i];
     for(i=0;i<length;i++)
     A[i]=B[i];

}
void Reverse2()
{
     int i,j;
     for(i=0,j=length-1;i<j;i++,j--)
     {
        swap(&A[i],&A[j]);
     }
}
void InsertSort(int x)
{
     int i=length-1;
     if(length==size)
        return;
     while(i>=0 && A[i]>x)
     {
         A[i+1]=A[i];
         i--;
     }
     A[i+1]=x;
     length++;

}
int isSorted()
{
     int i;
     for(i=0;i<length-1;i++)
     {
        if(A[i]>A[i+1])
            return 0;
     }
     return 1;
}
void Rearrange(struct Array *arr)
{
     int i,j;
     i=0;
     j=length-1;

     while(i<j)
     {
         while(A[i]<0)i++;
         while(A[j]>=0)j--;
         if(i<j) swap(&A[i],&A[j]);
     }

}
Array* Merge(Array arr2)
{
     int i,j,k;
     i=j=k=0;

     struct Array *arr3=(struct Array*)malloc(sizeof(struct Array));

     while(i<length && j<length)
     {
         if(A[i]<A[j])
            A[k++]=A[i++];
         else
            A[k++]=A[j++];
     }
     for(;i<length;i++)
     A[k++]=A[i];
     for(;j<length;j++)
     A[k++]=A[j];
     length=length+length;
     size=10;

     return arr3;
}
Array* Union(Array *arr2)
{
     int i,j,k;
     i=j=k=0;

     struct Array *arr3=(Array*)malloc(sizeof(struct Array));

     while(i<length && j<length)
     {
         if(A[i]<A[j])
            A[k++]=A[i++];
         else if(A[j]<A[i])
            A[k++]=A[j++];
         else
         {
             A[k++]=A[i++];
             j++;
         }
     }
     for(;i<length;i++)
        A[k++]=A[i];
     for(;j<length;j++)
        A[k++]=A[j];

     length=k;
     size=10;

     return arr3;
}
struct Array* Intersection(struct Array *arr1,struct
Array *arr2)
{
 int i,j,k;
 i=j=k=0;

 struct Array *arr3=(struct Array
*)malloc(sizeof(struct Array));

 while(i<length && j<length)
 {
 if(A[i]<A[j])
 i++;
 else if(A[j]<A[i])
 j++;
 else if(A[i]==A[j])
 {
 A[k++]=A[i++];
 j++;
 }
 }

 length=k;
 size=10;

 return arr3;
}
struct Array* Difference(struct Array *arr1,struct
Array *arr2)
{
 int i,j,k;
 i=j=k=0;

 struct Array *arr3=(struct Array
*)malloc(sizeof(struct Array));

 while(i<length && j<length)
 {
 if(A[i]<A[j])
 A[k++]=A[i++];
 else if(A[j]<A[i])
 j++;
 else
 {
 i++;
 j++;
 }
 }
 for(;i<length;i++)
 A[k++]=A[i];


 length=k;
 size=10;

 return arr3;
}
int main()
{


 printf("Enter Size of Array");
 scanf("%d",&arr1.size);

 arr1.length=0;
 do
 {
 printf("\n\nMenu\n");
 printf("1. Insert\n");
 printf("2. Delete\n");
 printf("3. Search\n");
 printf("4. Sum\n");
 printf("5. Display\n");
 printf("6.Exit\n");

 printf("enter you choice ");
 scanf("%d",&ch);

 switch(ch)
 {
 case 1: printf("Enter an element and index
");
 scanf("%d%d",&x,&index);
 Insert(&arr1,index,x);
 break;
 case 2: printf("Enter index ");
 scanf("%d",&index);
 x=Delete(&arr1,index);
 printf("Deleted Element is %d\n",x);
 break;
 case 3:printf("Enter element to search ");
 scanf("%d",&x);
 index=LinearSearch(&arr1,x);
 printf("Element index %d",index);
 break;
 case 4:printf("Sum is %d\n",Sum(arr1));
 break;
 case 5:Display(arr1);

 }
 }while(ch<6);
 return 0;
}

