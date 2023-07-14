#include <bits/stdc++.h>
using namespace std;

int matrix[1002][1002] = {0, };
int vis[1002];

int main() {
    int n, m;
    cin >> n >> m;
    while(m--) {
        int n1, n2;
        cin >> n1 >> n2;
        matrix[n1-1][n2-1] = 1;
        matrix[n2-1][n1-1] = 1;
    }

    fill(vis, vis+n, -1);
    stack<int> S;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(vis[i] != -1) continue;
        S.push(i);
        vis[i] = ++cnt;
        while(!S.empty()) {
            int cur = S.top(); S.pop();
            for(int i=0; i<n; i++) {
                if(matrix[cur][i] == 0) continue;
                if(vis[i] != -1) continue;
                vis[i] = cur;
                S.push(i);
            }
        }
    }
    
    cout << cnt << "\n";

    return 0;
}