#include <iostream>
using namespace std;
class Point
{
    int x;
    int y;

public:
    Point(int _x, int _y) : x(_x), y(_y) {}
    void print()
    {
        cout << "(" << x << "," << y << ")";
    }
    friend istream &operator>>(istream &is, Point &p); // LINE-1
    Point &operator++()
    {
        // LINE-2
        ++x;
        return *this;
    }
    Point &operator++(int)
    { // LINE-3

        ++y;
        return *this;
    }
};

istream &operator>>(istream &is, Point &p)
{ // LINE-4
    is >> p.x >> p.y;
    return is;
}
int main()
{
    int i, j;
    cin >> i >> j;
    Point p(i, j);
    ++(++p);
    p++;
    p.print();
    return 0;
}