#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define GREEN -2
#define RED -3
#define X first
#define Y second


// N, M : N X M
// G, R : 배양액 개수
// 0은 호수
// 1은 배양액을 뿌릴 수 없는 땅
// 2는 배양액을 뿌릴 수 있는 땅

int N, M, G, R;
int garden[52][52];
int state[52][52];
vector<pair<int, int>> possible; // possible point
int ans;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct Cell {
    int x, y, time, type;
};

int bfs(vector<pair<int, int>> &green, vector<pair<int, int>> &red) {
    queue<Cell> q;
    pair<int, int> visited[52][52];
    fill(&visited[0][0], &visited[0][0] + 52 * 52, make_pair(-1, -1));
    int flower_count = 0;

    for (auto g : green) {
        q.push({g.first, g.second, 0, GREEN});
        visited[g.first][g.second] = {GREEN, 0};
    }
    for (auto r : red) {
        q.push({r.first, r.second, 0, RED});
        visited[r.first][r.second] = {RED, 0};
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if(visited[cur.x][cur.y].first == RED+GREEN) continue; // 꽃이 이미 핀 경우
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (garden[nx][ny] == 0) continue; // 호수는 제외

            if (visited[nx][ny].first == -1) { 
                visited[nx][ny] = {cur.type, cur.time + 1};
                q.push({nx, ny, cur.time + 1, cur.type});
            } 
            else if (visited[nx][ny].first + cur.type == GREEN + RED &&
            visited[nx][ny].second == cur.time + 1) { 
                flower_count++;
                visited[nx][ny]= {RED+GREEN, cur.time+1}; // 꽃이 핀 경우
            }
        }
    }
    return flower_count;
}

void backtracking(int idx, int g, int r, vector<pair<int, int>> green, vector<pair<int, int>> red) {
    if(g == 0 && r == 0) {
        ans = max(ans, bfs(green, red));
        return;
    }

    for(int i=idx; i<possible.size(); i++) {
        if(g > 0) {
            green.push_back({possible[i].X, possible[i].Y});
            backtracking(i+1, g-1, r, green, red);
            green.pop_back();
        }
        if(r > 0) {
            red.push_back({possible[i].X, possible[i].Y});
            backtracking(i+1, g, r-1, green, red);
            red.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> G >> R;
    for(int i=0; i<N; i++) 
        for(int j=0; j<M; j++) {
            cin >> garden[i][j];
            if(garden[i][j] == 2) possible.push_back({i, j});
        }

    vector<pair<int, int>> green, red;
    backtracking(0, G, R, green, red);
    cout << ans << endl;
    
    return 0;
}