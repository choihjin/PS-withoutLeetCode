#include <bits/stdc++.h>
using namespace std;

int parent[10002];

int find(int x);
void Union(int x, int y);

int main() {
    int v, e, a, b, c;
    vector<pair<int, pair<int, int>>> tree;

    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        tree.push_back({c, {a, b}});
    }
    sort(tree.begin(), tree.end());

    for(int i = 0; i <= v; i++) 
        parent[i] = i;

    int sum = 0;
    for(int i = 0; i < e; i++) {
        int k = tree[i].first;
        int m = tree[i].second.first;
        int n = tree[i].second.second;
        if(find(m) == find(n)) continue; // If cycle pass

        Union(m, n);
        sum += k;
    }
    
    cout << sum << "\n";
    return 0;
}

int find(int x) 
{
    if(parent[x] == x) return x;
    else return find(parent[x]);
}

void Union(int x, int y) 
{
    int xRoot = find(x);
    int yRoot = find(y);
    parent[yRoot] = xRoot;
}