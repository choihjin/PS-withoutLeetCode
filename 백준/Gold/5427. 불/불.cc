#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
string board[1002];
int dist_F[1002][1002]; // 불의 전파 시간
int dist_J[1002][1002]; // 지훈이의 이동 시간
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    while(k--) {
        cin >> m >> n;
        for(int i=0; i<n; i++) {
            fill(dist_F[i], dist_F[i]+m, -1);
            fill(dist_J[i], dist_J[i]+m, -1);
        }
        for(int i=0; i<n; i++) cin >> board[i];

        queue<pair<int, int> > Q_F;
        queue<pair<int, int> > Q_J;
        // 시작점 찾기
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {       
                if(board[i][j] == '*') {
                    Q_F.push(make_pair(i, j));
                    dist_F[i][j] = 0;
                }
                if(board[i][j] == '@') {
                    Q_J.push(make_pair(i, j));
                    dist_J[i][j] = 0;
                }
            }
        }

        // 불의 BFS
        while(!Q_F.empty()) {
            pair<int, int> cur = Q_F.front(); Q_F.pop();
            for(int i=0; i<4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || nx >= n || ny < 0  || ny >= m) continue;
                if(dist_F[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                dist_F[nx][ny] = dist_F[cur.X][cur.Y]+1;
                Q_F.push(make_pair(nx, ny));
            }
        }
        
        bool check = false;
        // 지훈이의 BFS
        while(!Q_J.empty()) {
            pair<int, int> cur = Q_J.front(); Q_J.pop();
            for(int i=0; i<4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                // 범위를 벗어났다는 것은 탈출에 성공했다는 것을 의미. 큐에 거리순으로 들어가므로 최초에 탈출한 시간을 출력
                if(nx < 0 || nx >= n || ny < 0  || ny >= m) {
                    cout << dist_J[cur.X][cur.Y]+1 << "\n";
                    check = true;
                    break;
                }
                if(dist_J[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                // 불의 전파 시간을 조건에 추가
                if(dist_F[nx][ny] != -1 && dist_F[nx][ny] <= dist_J[cur.X][cur.Y]+1) continue;
                dist_J[nx][ny] = dist_J[cur.X][cur.Y]+1;
                Q_J.push(make_pair(nx, ny));
            }
            if(check) break;
        }

        // 여기에 도달한 것은 탈출에 실패한 것을 의미
        if(!check) cout << "IMPOSSIBLE\n";
    }
}