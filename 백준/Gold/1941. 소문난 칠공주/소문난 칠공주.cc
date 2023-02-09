#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

bool mask[25];
string board[5];
int ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i=0; i<5; i++) cin >> board[i];

  // 25명중 칠공주가 될 사람의 후보 조합을 뽑는다.
  fill(mask + 7, mask+25, true); // 25중에 7
  do {
    queue<pair<int, int>> Q;
    int cnt = 0;
    int k = 0;
    bool vis[5][5] = {};
    bool isp7[5][5] = {};
    for(int i=0; i<25; i++) {
      if(mask[i]) continue;
      int x = i / 5;
      int y = i % 5;
      isp7[x][y] = 1; // 이번에 선택된 조합을 체크
      if(Q.empty()) {
        Q.push({x, y});
        vis[x][y] = 1;
      }
    }

    // BFS
    while(!Q.empty()) {
      auto cur = Q.front(); Q.pop();
      k++;
      if(board[cur.X][cur.Y] == 'S') cnt++;
      for(int i=0; i<4; i++) {
        int nx = cur.X + dx[i];
        int ny = cur.Y + dy[i];
        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if(vis[nx][ny] || !isp7[nx][ny]) continue;
        Q.push({nx, ny});
        vis[nx][ny] = 1;
      }
    }
    if(k == 7 && cnt >= 4) ans++;
    
  } while(next_permutation(mask, mask+25));
  
  cout << ans << "\n";
}