#include <iostream>
using namespace std;
class A
{
    int a;

public:
    A(int _a = 0);
    int sum();
};
class B : public A
{
    int b;

public:
    B(int _a = 0, int _b = 0);
    int sum();
};
class C : public B
{
    int c;

public:
    C(int _a = 0, int _b = 0, int _c = 0);
    int sum();
};

A::A(int _a) : a(_a) {}                            // LINE-1
B::B(int _a, int _b) : A(_a), b(_b) {}             // LINE-2
C::C(int _a, int _b, int _c) : B(_a, _b), c(_c) {} // LINE-3
int A::sum() { return a; }                         // LINE-4
int B::sum() { return this->b + A::sum(); }        // LINE-5
int C::sum() { return this->c + B::sum(); }        // LINE-6
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    A aObj(a);
    B bObj(a, b);
    C cObj(a, b, c);
    cout << aObj.sum() << ", " << bObj.sum() << ", " << cObj.sum();
    return 0;
}
