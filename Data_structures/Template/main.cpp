#include <iostream>
using namespace std;
/* class!!!!!!!!! 
class arith{
private:
    int a;
    int b;
public:
    arith(int a,int b);
    int add();
    int sub();
    ~arith(){};
};

arith::arith(int a1,int b1){
    a=a1;
    b=b1;
}
int arith::add(){
    int c;
    c=a+b;
    return c;
}
int arith::sub(){
    int c;
    c=a-b;
    return c;
}

int main(){
    arith ar(10,5);
    cout<<ar.add()<<endl<<ar.sub();
}*/
template<class t>
class arith{
private:
    t a;
    t b;
public:
    arith(t a,t b);
    t add();
    t sub();
    ~arith(){};
};
template<class t>
arith<t>::arith(t a,t b){
    this->a=a;
    this->b=b;
}
template<class t>
t arith<t>::add(){
    t c;
    c=a+b;
    return c;
}
template<class t>
t arith<t>::sub(){
    t c;
    c=a-b;
    return c;
}

int main(){
    arith<float> ar(10.55,5.2);
    cout<<ar.add()<<endl<<ar.sub();
}