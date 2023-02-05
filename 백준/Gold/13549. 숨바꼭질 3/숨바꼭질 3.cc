#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dist[200002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    fill(dist, dist+200002, -1);

    queue<int> Q;
    dist[n] = 0;
    Q.push(n);
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nxt : {2*cur, cur-1, cur+1}) {
            if(nxt < 0 || nxt >= 200002) continue;
            if(dist[nxt] >= 0) continue;
            
            if(nxt == 2*cur) dist[nxt] = dist[cur];
            else dist[nxt] = dist[cur]+1;
            Q.push(nxt);
        }
    }

    cout << dist[k] << "\n";
}