#include <iostream>
#include <vector>

using namespace std;

int n = 1005;
int father[1005];

void init()
{
    for (int i = 0; i < n; i++)
    {
        father[i] = i;
    }
}
int find(int u)
{
    return u == father[u] ? u : father[u] = find(father[u]);
}
void join(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    father[v] = u;
}
bool same(int u, int v)
{
    u = find(u);
    v = find(v);
    return u == v;
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    init();
    for (int i = 0; i < edges.size(); i++)
    {
        if (same(edges[i][0], edges[i][1]))
            return edges[i];
        else
            join(edges[i][0], edges[i][1]);
    }
    return {};
}

int main() {
    // vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    vector<vector<int>> edges = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    vector<int> result = findRedundantConnection(edges);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}