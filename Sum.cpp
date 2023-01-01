#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <bits/stdc++.h>

using namespace std;

namespace testinfra
{

    class Sum
    {
    public:
        bool test()
        {
            long long target;
            int sz;
            cin >> target >> sz;

            vector<int> in;
            in.reserve(sz);
            for (int i = 0; i < sz; i++)
            {
                int j;
                cin >> j;
                in.push_back(j);
            }

            return this->impl(in, target);
        }

    private:
        bool impl(vector<int> const &a, long long s)
        {
            // TODO
            map<int, int> m;
            for (int i = 0; i < a.size(); i++)
            {
                if (m[s - a[i]])
                {
                    return true;
                }
                m[a[i]]++;
            }
            return false;
        }
    };

}

using namespace testinfra;

int main(int arg, char **argv)
{
    Sum s;
    cout << boolalpha << s.test() << endl;
}
