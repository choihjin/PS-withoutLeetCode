#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m;
vector<int> adj[32002];
int deg[32002];

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    queue<int> q;
    vector<int> ans;
    for(int i=1 ;i<=n; i++) // indegree 계산
        if(deg[i] == 0) q.push(i);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for(int nxt : adj[cur]) {
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }

    if(ans.size() != n) cout << "cycle" << endl;
    else for(int i : ans) cout << i << " ";
    cout << endl;

    return 0;
}