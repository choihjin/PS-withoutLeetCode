#include <bits/stdc++.h>
using namespace std;

int board[202][202];
int dist[32][202][202];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int dx2[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy2[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };
queue<tuple<int, int, int>> Q;
int n, m, k;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> m >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    Q.push({ 0, 0, 0 });
    dist[0][0][0] = 1;
    while (!Q.empty()) {
        int horse, x, y;
        tie(horse, x, y) = Q.front(); Q.pop();
        if (horse < k) {
            for (int i = 0; i < 8; i++) {
                int nx = x + dx2[i], ny = y + dy2[i];
                if (nx < 0 || ny < 0 || n <= nx || m <= ny) continue;
                if (board[nx][ny] || dist[horse + 1][nx][ny]) continue;
                dist[horse + 1][nx][ny] = dist[horse][x][y] + 1;
                Q.push({ horse + 1, nx, ny });
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || n <= nx || m <= ny) continue;
            if (board[nx][ny] || dist[horse][nx][ny]) continue;
            dist[horse][nx][ny] = dist[horse][x][y] + 1;
            Q.push({ horse, nx, ny });
        }
    }

    // 최대값에 가까운 값으로 선언
    int ans = 0x7f7f7f7f;
    for (int i = 0; i < k + 1; i++)
        if(dist[i][n - 1][m - 1]) ans = min(ans, dist[i][n - 1][m - 1]);

    if (ans != 0x7f7f7f7f) cout << ans - 1;
    else cout << -1;
}