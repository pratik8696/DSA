#include <bits/stdc++.h>
using namespace std;
// Class Solution with shortestPath function to find the shortest path
class Solution
{
public:
    // vector to store the parents of nodes while finding the shortest path
    vector<long long> p;

    // recursive function to find the shortest path from start to end
    void f(long long i, vector<int> &ans)
    {
        // if not the first node, recursively call f function for the parent node
        if (i != 1)
            f(p[i], ans);
        // add the current node to the answer vector
        ans.push_back(i);
    }

    // function to find the shortest path in an undirected graph
    vector<int> shortestPath(int n, int m1, vector<vector<int>> &edges)
    {
        // map to store the edges and their weights
        map<pair<long long, long long>, long long> m;
        // vector to store the adjacency list representation of the graph
        vector<long long> v[n + 1];

        // fill the adjacency list and edge weight map
        for (auto x : edges)
        {
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
            m[{x[0], x[1]}] = x[2];
            m[{x[1], x[0]}] = x[2];
        }

        // resize the parent array and distance array
        p.resize(n + 1);
        vector<long long> dis(n + 1, 1e18);
        // set the distance of the start node to 0
        dis[1] = 0;

        // priority queue to store the vertices and their distances
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            pq;
        // push the start node with distance 0 to the priority queue
        pq.push({0, 1});

        // Dijkstra's algorithm to find the shortest path
        while (!pq.empty())
        {
            // get the vertex with the minimum distance from the priority queue
            pair<long long, long long> p1 = pq.top();
            pq.pop();
            long long x = p1.first;
            long long y = p1.second;

            // iterate over the neighbors of the current vertex
            for (long long i = 0; i < v[y].size(); i++)
            {
                long long z = v[y][i];
                long long w = m[{z, y}]; // get the edge weight

                // if the distance from start node to the neighbor node through current node is smaller
                // than the previously computed distance, update the distance and parent
                if (dis[y] + w < dis[z])
                {
                    dis[z] = dis[y] + w;
                    p[z] = y;
                    // push the updated distance and neighbor node to the priority queue
                    pq.push({dis[z], z});
                }
            }
        }

        vector<int> ans;
        // if the distance to the destination node is still infinity, there is no path
        if (dis[n] == 1e18)
        {
            ans.push_back(-1);
            return ans;
        }

        // call the recursive function to find the shortest path and store it in the answer vector
        f(n, ans);

        // return the shortest path
        return ans;
    }
};

int main()
{
    freopen("1000input.txt", "r", stdin);
    freopen("1000output.txt", "w", stdout);
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        char x;
        cin >> x;

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << endl;

        cout << "~" << endl;
    }
}
