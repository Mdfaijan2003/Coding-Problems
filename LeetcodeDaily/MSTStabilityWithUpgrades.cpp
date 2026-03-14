/*3600. Maximize Spanning Tree Stability with Upgrades
Hard

You are given an integer n, representing n nodes numbered from 0 to n - 1 and a list of edges, where edges[i] = [ui, vi, si, musti]:

ui and vi indicates an undirected edge between nodes ui and vi.
si is the strength of the edge.
musti is an integer (0 or 1). If musti == 1, the edge must be included in the spanning tree. These edges cannot be upgraded.
You are also given an integer k, the maximum number of upgrades you can perform. Each upgrade doubles the strength of an edge, and each eligible edge (with musti == 0) can be upgraded at most once.

The stability of a spanning tree is defined as the minimum strength score among all edges included in it.

Return the maximum possible stability of any valid spanning tree. If it is impossible to connect all nodes, return -1.

Note: A spanning tree of a graph with n nodes is a subset of the edges that connects all nodes together (i.e. the graph is connected) without forming any cycles, and uses exactly n - 1 edges.



Example 1:

Input: n = 3, edges = [[0,1,2,1],[1,2,3,0]], k = 1

Output: 2

Explanation:

Edge [0,1] with strength = 2 must be included in the spanning tree.
Edge [1,2] is optional and can be upgraded from 3 to 6 using one upgrade.
The resulting spanning tree includes these two edges with strengths 2 and 6.
The minimum strength in the spanning tree is 2, which is the maximum possible stability.
Example 2:

Input: n = 3, edges = [[0,1,4,0],[1,2,3,0],[0,2,1,0]], k = 2

Output: 6

Explanation:

Since all edges are optional and up to k = 2 upgrades are allowed.
Upgrade edges [0,1] from 4 to 8 and [1,2] from 3 to 6.
The resulting spanning tree includes these two edges with strengths 8 and 6.
The minimum strength in the tree is 6, which is the maximum possible stability.
Example 3:

Input: n = 3, edges = [[0,1,1,1],[1,2,1,1],[2,0,1,1]], k = 0

Output: -1

Explanation:

All edges are mandatory and form a cycle, which violates the spanning tree property of acyclicity. Thus, the answer is -1.*/

// Intuitive Approach-->
/*We want the maximum possible minimum edge strength in our spanning tree, so we use binary search on the answer. For a candidate "mid" value, we check feasibility by first processing all mandatory edges—if any mandatory edge has strength less than mid, it's immediately impossible. Then we include all optional edges that already have strength ≥ mid for free, and finally use our k upgrades on optional edges that can reach ≥ mid after doubling, but only when they help connect different components. After processing everything, if we've used exactly n-1 edges and all nodes are connected, then this mid value is achievable. Since higher mid values are harder to achieve, we binary search to find the maximum feasible value, and if the graph isn't connected at all or mandatory edges form a cycle, we return -1.*/

#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void Union(int u, int v)
    {
        int ult_u = findPar(u);
        int ult_v = findPar(v);
        if (ult_u == ult_v)
            return;

        if (rank[ult_u] < rank[ult_v])
        {
            parent[ult_u] = ult_v;
        }
        else if (rank[ult_u] > rank[ult_v])
        {
            parent[ult_v] = ult_u;
        }
        else
        {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

bool check(int n, vector<vector<int>> &edges, int k, int mid)
{
    DSU dsu(n);
    vector<vector<int>> upgrade;

    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1], s = edge[2], m = edge[3];

        if (m == 1)
        {
            if (s < mid)
                return false;

            dsu.Union(u, v);
        }
        else
        {
            if (s >= mid)
                dsu.Union(u, v);
            else
            {
                if (2 * s >= mid)
                    upgrade.push_back({u, v});
            }
        }
    }

    for (auto &edge : upgrade)
    {
        int u = edge[0];
        int v = edge[1];

        if (dsu.findPar(u) != dsu.findPar(v))
        {
            if (k < 0)
                return false;

            dsu.Union(u, v);
            k--;
        }
    }

    int root = dsu.findPar(0);
    for (int i = 1; i <= n - 1; i++)
    {
        if (dsu.findPar(i) != root)
        {
            return false;
        }
    }
    return true;
}

int maxStability(int n, vector<vector<int>> &edges, int k)
{

    DSU dsu(n);
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1];
        int m = edge[3];

        if (m == 1)
        {
            if (dsu.findPar(u) == dsu.findPar(v))
                return -1;

            dsu.Union(u, v);
        }
    }

    // Binary search on answer
    int l = 1;
    int r = 2 * 1e5;
    int result = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (check(n, edges, k, mid))
        {
            result = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return result;
}

int main()
{

    vector<vector<int>> edges1 = {{0, 1, 2, 1}, {1, 2, 3, 0}};
    cout << "Test 1: " << maxStability(3, edges1, 1) << " (Expected: 2)" << endl;

    vector<vector<int>> edges2 = {{0, 1, 4, 0}, {1, 2, 3, 0}, {0, 2, 1, 0}};
    cout << "Test 2: " << maxStability(3, edges2, 2) << " (Expected: 6)" << endl;

    vector<vector<int>> edges3 = {{0, 1, 1, 1}, {1, 2, 1, 1}, {2, 0, 1, 1}};
    cout << "Test 3: " << maxStability(3, edges3, 0) << " (Expected: -1)" << endl;

    return 0;
}