#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef long long ll;
int n, m, k;
int stone[1002][1002];
int visited[1002][1002];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(ll cond) {
    int ret = 0;
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> Q;

    // start point
    for(int i = 0; i < m; i++) {
        if(stone[0][i] <= cond) {
            Q.push({0, i});
            visited[0][i] = 1;
            ret++;
        }
    }
    for(int i = 1; i < n; i++) {
        if(stone[i][0] <= cond) {
            Q.push({i, 0}); 
            visited[i][0] = 1;
            ret++;
        }

        if(stone[i][m-1] <= cond) {
            Q.push({i, m-1});
            visited[i][m-1] = 1;
            ret++;
        }
    }

    // BFS
    while(!Q.empty()) {
        int x, y;
        tie(y, x) = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(stone[ny][nx] > cond || visited[ny][nx]) continue;

            Q.push({ny, nx});
            visited[ny][nx] = 1;
            ret++;
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            cin >> stone[i][j];

    ll st = 1, en = 1'000'000;
    ll ans = -1;

    while (st <= en) {
        ll mid = (st + en) / 2;
        int cnt = bfs(mid);  

        if (cnt >= k) {
            ans = mid;       
            en = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}