#include <iostream>
using namespace std;

class myClass
{
    int x, y;
    // static int z; // LINE-1

public:
    // myClass(int x_, int y_) : x(x_ * x_), y(y_ * y_) {}
    friend ostream &operator<<(ostream &os, const Point &a)
    {
        os << a.x << " " << a.y << endl;
        return os;
    }
    friend istream &operator>>(istream &io, Point &a)
    {
        io >> a.x >> a.y;
        return io;
    }
};

// int myClass::z = 0;

int main()
{
    myClass myclass;
    cin >> myclass;
    cout << myclass;
    // m.calulateZ();
    // m.print();

    return 0;
}