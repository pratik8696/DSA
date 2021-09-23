#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> m;

    /* for inserting any values we make the pair
     of those things and then we insert in the 
     map data structure */

    // first way
    m.insert(make_pair("mango", 10));

    // second way
    pair<string, int> p;
    p.first = "banana";
    p.second = 20;
    m.insert(p);

    // third way
    m["apple"] = 30;

    // Searching in a map function
    string fruit;
    cin >> fruit;

    auto it = m.find(fruit);
    if (it != m.end())
    {
        cout << "price of fruit " << fruit << " is " << m[fruit] << endl;
    }
    else
    {
        cout << "fruit is not present" << endl;
    }


    /*  */

    return 0;
}