#include <iostream>
using namespace std;
int main(){
    int a=10;
    int &b=a;
    // now a and b represent same memory location
    cout<<a<<" "<<b<<" "<<" "<<&a<<" "<<&b;
    return 0;
}