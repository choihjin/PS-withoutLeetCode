#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[302][302];
int dist[302][302];
int n;
// 나이트의 이동에 맞게 변경
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    int m;
    cin >> m;
    while(m--) {
        cin >> n;
        queue<pair<int,int>> Q;
        for(int i=0; i<n; i++) fill(dist[i], dist[i]+n, -1);

        int g, h;
        cin >> g >> h;
        dist[g][h] = 0;
        Q.push({g, h});

        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for(int i=0; i<8; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.X][cur.Y]+1;
                Q.push({nx, ny});
            }
        }

        cin >> g >> h;
        cout << dist[g][h] << "\n";
    }
}