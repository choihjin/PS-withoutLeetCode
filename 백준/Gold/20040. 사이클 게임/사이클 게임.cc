#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m;
vector<int> p(500'002, -1);

int find(int x) {
    if(p[x] < 0) 
        return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v)
        return false;
    p[v] = u;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if(!uni(u, v)) {
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}