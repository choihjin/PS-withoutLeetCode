#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

#define AIR 0
#define CHEESE 1
#define OUTER_AIR 2

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;
int space[102][102];

void update_outer() {
    // outer air
    queue<pair<int, int>> Q;
    int visited[102][102];
    memset(visited, 0, sizeof(visited));

    Q.push({0, 0});
    visited[0][0] = 1;
    while(!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        space[y][x] = OUTER_AIR;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (visited[ny][nx] || space[ny][nx] == CHEESE) continue;

            Q.push({nx, ny});
            visited[ny][nx] = 1;
        }
    }
}

int melting_cheese() {
    int tmp[102][102];
    memcpy(tmp, space, sizeof(tmp));

    int cheese_cnt = 0;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (space[i][j] == CHEESE) {
                int cnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = j + dx[dir];
                    int ny = i + dy[dir];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (space[ny][nx] == OUTER_AIR) cnt++;
                }

                if (cnt >= 2) tmp[i][j] = OUTER_AIR;
                else cheese_cnt++;
            }
        }
    }

    memcpy(space, tmp, sizeof(space));

    return cheese_cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> space[i][j];
        }
    }

    int time = 1;
    while(1) {
        update_outer();
        
        int res = melting_cheese();
        if(res == 0) break;

        time++;
    }

    cout << time << endl;

    return 0;
}