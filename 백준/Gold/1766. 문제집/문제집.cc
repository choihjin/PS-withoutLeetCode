#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m;
vector<int> adj[32002];
int deg[32002];

int main() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=1; i<=n; i++)
        if(deg[i] == 0) q.push(i);
    
    while(!q.empty()) {
        int cur = q.top(); q.pop();
        ans.push_back(cur);
        for(int nxt : adj[cur]) 
            if(--deg[nxt] == 0) q.push(nxt);
    }

    if(ans.size() != n) cout << "cycle exists" << endl;
    else 
        for(int a : ans) cout << a << " ";
    cout << endl;
}