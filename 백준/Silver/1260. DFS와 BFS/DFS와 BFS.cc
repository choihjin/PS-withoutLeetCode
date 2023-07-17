#include <bits/stdc++.h>
using namespace std;

int matrix[1002][1002];
int vis[1002];

int main() {
   int n, m, start;
    cin >> n >> m >> start;
    while(m--) {
        int n1, n2;
        cin >> n1 >> n2;
        matrix[n1][n2] = 1;
        matrix[n2][n1] = 1;
    }

    stack<int> S;
    S.push(start);
    while(!S.empty()) {
        if(vis[S.top()] == 1) {
            S.pop();
            continue;
        }

        cout << S.top() << " ";
        int cur = S.top(); S.pop();
        vis[cur] = 1;
        for(int i=n; i>0; i--) {
            if(matrix[cur][i] == 0 || vis[i] == 1) continue;
            S.push(i);
        }
    }
    cout << "\n";

    fill(vis, end(vis), 0);
    queue<int> Q;
    vis[start] = 1;
    Q.push(start);
    while(!Q.empty()) {
        cout << Q.front() << " ";
        int cur = Q.front(); Q.pop();
        for(int i=1; i<=n; i++) {
            if(matrix[cur][i] != 1 || vis[i] == 1) continue;
            Q.push(i);
            vis[i] = 1;
        }
    }
    cout << "\n";
}