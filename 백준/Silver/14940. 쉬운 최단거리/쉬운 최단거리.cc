#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define endl "\n"

int matrix[1002][1002];
int vis[1002][1002];
int n, m;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    queue<pair<int, int> > Q;

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        fill(vis[i], vis[i]+m, -1);
        for(int j=0; j<m; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] == 2) {
                vis[i][j] = 0;
                Q.push({i, j});
            }
            else if(matrix[i][j] == 0)
                vis[i][j] = 0;
        }
    }
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] >= 0) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push(make_pair(nx,ny));
        }
    }

    // cout << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}