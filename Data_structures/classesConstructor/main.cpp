#include <iostream>

class rectangle{
private:
    int length=0;
    int breadth=0;
public:
    rectangle(){
        length=0;
        breadth=0;
    }
    rectangle(int l,int b){
        printf("created\n");
        length=l;
        breadth=b;
    }
    int area(){
        return length*breadth;
    }
    int perimeter(){
        return 2*(length+breadth);
    }
    void setLength(int l){
        length=l;
    }
    void setBreadth(int b){
        breadth=b;
    }
    int getLength(){
        return length;
    }
    int getBreadth(){
        return breadth;
    }
    ~rectangle(){printf("\nDestroyed");};
};
int main(){
	rectangle r{5,10};
    std::cout<<r.area()<<std::endl<<r.perimeter();
}
