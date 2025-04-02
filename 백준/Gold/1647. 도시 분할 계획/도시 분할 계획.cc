#include<bits/stdc++.h>
using namespace std;

int v, e;
tuple<int, int, int> edge[1000002];
vector<int> p(100002, -1);

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return 0;
    if (p[u] == p[v]) p[u]--;
    if (p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {c, a, b};
    }
    sort(edge, edge + e);

    int cnt = 0;
    vector<int> ans;
    for(int i = 0; i < e; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        ans.push_back(cost);
        cnt++;
        if(cnt == v-1) break;
    }

    sort(ans.begin(), ans.end());
    ans.pop_back();

    int sum = 0;
    for(auto a : ans) sum += a;
    cout << sum << endl;
        
    return 0;
}