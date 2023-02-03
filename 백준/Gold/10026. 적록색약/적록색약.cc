#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[105];
bool vis[105][105];
queue<pair<int, int> > Q;
int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

void bfs(int i, int j) {
    vis[i][j] = true;
    Q.push(make_pair(i, j));
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int k=0; k<4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;
            vis[nx][ny] = true;
            Q.push(make_pair(nx, ny));
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    // 적록색약인 사람은 구분을 못하기 때문에 board2에는 G를 R로 저장
    for(int i=0; i<n; i++) cin >> board[i];

    // 적록색약이 아닌 사람의 구역 카운트
    int count1 = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!vis[i][j]) {
                count1++;
                bfs(i, j);
            }
        }
    }
    cout << count1 << "\n";

    for(int i=0; i<n; i++) {
        fill(vis[i], vis[i]+n, false);
        for(int j=0; j<n; j++) {
            if(board[i][j] == 'G') board[i][j] = 'R';
        }
    }

    // 적록색약인 사람의 구역 카운트
    int count2 = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!vis[i][j]) {
                count2++;
                bfs(i, j);
            }
        }
    }
    cout << count2 << "\n";
}