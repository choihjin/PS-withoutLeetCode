#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[302][302];
int c[302][302];
bool vis[302][302];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) 
            cin >> board[i][j];

    int res = 1;
    int num = 0;
    for(;;res++) {
        // reset
        for(int i=0; i<n; i++) {
            fill(vis[i], vis[i]+m, false);
            fill(c[i], c[i]+m, 0);
        }

        // 주변의 바다만큼 녹는것을 계산
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] > 0) {
                    int count = 0;
                    for(int k=0; k<4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(board[nx][ny] == 0) count++;
                    }
                    c[i][j] = count;
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] - c[i][j] <= 0) board[i][j] = 0;
                else board[i][j] -= c[i][j];
            }
        }

        // BFS
        num = 0;
        queue<pair<int, int>> Q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] > 0 && !vis[i][j]) {
                    num++;
                    vis[i][j] = true;
                    Q.push({i, j});
                    while(!Q.empty()) {
                        auto cur = Q.front(); Q.pop();
                        for(int k=0; k<4; k++) {
                            int nx = cur.X + dx[k];
                            int ny = cur.Y + dy[k];
                            if(nx < 0 || nx >= n || ny < 0  || ny >= m) continue;
                            if(board[nx][ny] == 0 || vis[nx][ny]) continue;
                            vis[nx][ny] = true;
                            Q.push({nx, ny});
                        }
                    }
                }
            }
        }

        if(num != 1) break;
    }

    if(num != 0) cout << res << "\n";
    else cout << 0 << "\n";
}