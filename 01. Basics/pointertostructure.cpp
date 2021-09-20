#include <iostream>
using namespace std;

struct array{
    int n;
    int size;
};

int main(){
    struct array one;
    struct array two;
    // passing the address of the structure to the structure pointers
    struct array *q=&two;
    struct array *p=&one;
    // This method is quite different so we use (*p).length
    (*p).n=10;
    (*p).size=100;
    // and also a bit confusing
    q->n=20;
    q->size=100000;
    // output
    cout<<one.n<<" "<<one.size<<endl;
    cout << two.n << " " << two.size << endl;
}