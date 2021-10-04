#include <iostream>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};

int main(){ 
    struct rectangle *p;
    p=(struct rectangle*)malloc(sizeof(struct rectangle));
    p->length=20;
    p->breadth=100;
    // another structure
    struct rectangle *q;
    q=new struct rectangle;
    q->length=1000;
    q->breadth=200;
    return 0;
}