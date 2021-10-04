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
    // another way of searching for a key in a map
    if(m.count(fruit))
    {
        cout<<"The fruit is present and its price is = "<<m[fruit]<<endl;
    }
    else{
        cout<<"The fruit is not present"<<endl;
    }
    // now deleting the key value pair
    m.erase(fruit);
    // iterating over all key value pair
    m["lichi"]=50;
    m["strawberry"]=70;
    m["pineapple"]=90;
    // using for each loop
    cout<<"Iterating using for each loop"<<endl;
    for(auto p:m)
    {
        cout<<p.first<<" : "<<p.second<<endl;
    }
    // now using normal for loop
    m.erase("apple");
    cout << "Iterating using normal for loop" << endl;
    for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->first<<" -> "<<i->second<<endl;
    }

    return 0;
}