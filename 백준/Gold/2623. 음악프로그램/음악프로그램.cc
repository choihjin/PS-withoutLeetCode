#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m;
vector<int> adj[32002];
int deg[32002];

int main() {
    cin >> n >> m;
    cin.ignore();
    
    for(int i=0; i<m; i++) {
        string str;
        stringstream ss;
        int a, b;
        getline(cin, str);
        ss.str(str);
        ss >> a;
        ss >> a;
        while(ss >> b) {
            adj[a].push_back(b);
            deg[b]++;
            a = b;
        }
    }

    queue<int> q;
    vector<int> ans;
    for(int i=1; i<=n; i++) {
        if(deg[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for(int nxt : adj[cur]) 
            if(--deg[nxt] == 0) q.push(nxt);
    }

    if(ans.size() != n) cout << 0 << endl;
    else for(auto a : ans) cout << a << endl;
    cout << endl;

    return 0;
}