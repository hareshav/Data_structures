#include <iostream>
#include <stdlib.h>
using namespace std;
class Heap{
private:
    int *array;
    int MaxSize,noel;
    void Adjust(int i,int n);
public:
    void insert(int item);
    void print();
    int deleteheap();
    Heap(int size){
        array=(int *)malloc(sizeof(int)*(size+1));
    }
//    ~Heap();
};
void Heap::insert(int item){
    int i=++noel;
    if(i==MaxSize){
        cout<<"Heap Full"<<endl;
        return;
    }
    while(i>1&&array[i/2]<item){
        array[i]=array[i/2];
        i=i/2;
    }
    array[i]=item;
}
void Heap::print(){
    for(int i=1;i<=noel;i++){
        printf("%d ",array[i]);
    }
}
void Heap::Adjust(int i,int n){
    int j=2*i;
    int item=array[i];
    while(j<=n){
        if(j<n && array[j]<array[j+1])j++;
        if(item>=array[j]&& item>=array[j+1])break;
        array[j/2]=array[j];
        j=j*2;
    }
    [j/2]=item;
}
int Heap::deleteheap(){
    int x=array[1];
    array[1]=array[noel--];
    Adjust(1,noel);
}
int main()
{
	Heap h(5);
    h.insert(5);
    h.insert(10);
//    h.insert(15);
    h.insert(17);
    h.insert(15);
    h.deleteheap();
    h.print();
}
