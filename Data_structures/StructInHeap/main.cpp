#include <stdio.h>
#include <stdlib.h>
struct rec{
    int b;
    int l;
};
struct rec* fun(){
    struct rec *p;
    p=(struct rec *)malloc(sizeof(struct rec));
    p->b=-5;
    p->l=-10;
    return p;
}
int main()
{
    struct rec *p;
    p=fun();
    printf("%d %d",(*p).l,p->b);
	return 0;
}
