#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
string board[1002];
int dist[1002][1002][2];
// dist[x][y][0] : 벽을 하나도 부수지 않고 (x,y)까지 오는데 걸리는 비용
// dist[x][y][1] : 벽을 하나만 부수고 (x,y)까지 오는데 걸리는 비용, (x,y)가 벽이라서 부수는 경우 포함
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> board[i];
        for(int j=0; j<m; j++) {
            dist[i][j][0] = -1;
            dist[i][j][1] = -1;
        }
    }

    queue<tuple<int, int, int>> Q;
    dist[0][0][0] = dist[0][0][1] = 1;
    Q.push({0, 0, 0});
    while(!Q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = Q.front(); Q.pop();
        if(x == n-1 && y == m-1) {
            cout << dist[x][y][broken] << "\n";
            break;
        }
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
                dist[nx][ny][broken] = dist[x][y][broken]+1;
                Q.push({nx, ny, broken});
            }
            // (nx, ny)를 부수는 경우
            if(!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = dist[x][y][broken]+1;
                Q.push({nx, ny, 1});
            }
        }
    }
    
    if(dist[n-1][m-1][0] == -1 && dist[n-1][m-1][1] == -1) cout << -1 << "\n";
}