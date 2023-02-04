#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[102][102][102];
int dist[102][102][102];
int m, n, h;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0 , -1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main() {
    cin >> m >> n >> h;
    queue<tuple<int, int, int> > Q;
    for(int k=0; k<h; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> board[i][j][k];
                if(board[i][j][k] == 1) Q.push({i, j, k});
                if(board[i][j][k] == 0) dist[i][j][k] = -1;
            }
        }
    }

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur;
        for(int i=0; i<6; i++) {
            int nx = curX+ dx[i];
            int ny = curY + dy[i];
            int nz = curZ + dz[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if(dist[nx][ny][nz] >= 0) continue;
            dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
            Q.push({nx, ny, nz});
        }
    }

    int mx = 0;
    for(int k=0; k<h; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dist[i][j][k] == -1) {
                    cout << -1 << "\n";
                    return 0;
                }
                mx = max(mx, dist[i][j][k]);
            }
        }
    }
    cout << mx << "\n";
    return 0;

}