#include <iostream>
using namespace std;

class rectangle {
public:
    int l;
    int b;
    void initialize(int lc,int bc){
        l=lc;
        b=bc;
    }

    int area(){
        return l*b;
    }
    int perimeter(){
        int p=0;
        p=2*(l+b);
        return p;
    }
};
int main()
{
	int l=0,b=0;
    struct rectangle r;
    cout<<"Enter length and breadth"<<endl;
    cin>>l>>b;
    r.initialize(l,b);
    int a=r.area();
    int p=r.perimeter();
    cout<<"Area :"<<a<<endl<<"Perimeter :"<<p;
	return 0;
}
