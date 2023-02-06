#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[102][102];
bool vis[102][102];
int dist[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
queue<pair<int, int>> Q;
queue<pair<int, int>> Q2;

int main() {
  cin >> n;
  for(int i=0; i<n; i++) {
    fill(dist[i], dist[i]+n, -1);
    for(int j=0; j<n; j++) cin >> board[i][j];
  }

  // 같은 섬마다 번호를 부여
  int num = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(board[i][j] == 0 || vis[i][j]) continue;
      num++;
      vis[i][j] = 1;
      board[i][j] = num;
      Q.push({i,j});
      while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if(vis[nx][ny] || board[nx][ny] == 0) continue;
          board[nx][ny] = num;
          vis[nx][ny] = 1;
          Q.push({nx,ny});
        }
      }
    }
  }

  // 모든 육지 (i, j) 각각에 대해 bfs를 진행. 이 때 board[i][j]와
  // board[nx][ny]가 다른 최초의 (nx, ny)를 찾으면 (i, j)에서 시작하는 다리의 길이를 계산 가능.
  int ans = 0x7f7f7f7f;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(board[i][j]) {
        dist[i][j] = 0;
        Q.push({i, j});
        
        while(!Q.empty()) {
          auto cur = Q.front(); Q.pop();
          for(int k=0; k<4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[i][j] == board[nx][ny] || dist[nx][ny] >= 0) continue;
            if(board[nx][ny] && board[i][j] != board[nx][ny]) {
              ans = min(ans, dist[cur.X][cur.Y]);
              while(!Q.empty()) Q.pop();
            }
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            Q.push({nx, ny});
          }
        }

        for(int k=0; k<n; k++) fill(dist[k], dist[k]+n, -1);
      }
    }
  }
  cout << ans << "\n";
}