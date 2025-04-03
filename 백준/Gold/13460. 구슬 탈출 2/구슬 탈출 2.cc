#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

struct State {
    int rx, ry; // R 위치
    int bx, by; // B 위치
    int cnt;    // 움직인 횟수
};

int n, m;
string board[12];
bool visited[12][12][12][12]; // rx, ry, bx, by 상태 전부 기록
queue<State> Q;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(&visited[0][0][0][0], &visited[0][0][0][0] + sizeof(visited), false);
    State tmp;
    tmp.cnt = 0;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
        for(int j = 0; j < board[i].size(); j++) {
            if(board[i][j] == 'R') {
                tmp.rx = i;
                tmp.ry = j;
            }
            if(board[i][j] == 'B') {
                tmp.bx = i;
                tmp.by = j;
            }
        }
    }
    Q.push(tmp);
    visited[tmp.rx][tmp.ry][tmp.bx][tmp.by] = tmp.cnt;

    while(!Q.empty()) {
        State cur;
        cur = Q.front(); Q.pop();

        if (cur.cnt >= 10) continue;

        for (int dir = 0; dir < 4; dir++) {
            int nrx = cur.rx, nry = cur.ry;
            int nbx = cur.bx, nby = cur.by;

            bool red_in_hole = false, blue_in_hole = false;

            // Move R
            while (board[nrx + dx[dir]][nry + dy[dir]] != '#' && board[nrx][nry] != 'O') {
                nrx += dx[dir];
                nry += dy[dir];
                if (board[nrx][nry] == 'O') red_in_hole = true;
            }

            // Move B
            while (board[nbx + dx[dir]][nby + dy[dir]] != '#' && board[nbx][nby] != 'O') {
                nbx += dx[dir];
                nby += dy[dir];
                if (board[nbx][nby] == 'O') blue_in_hole = true;
            }

            // Hole case
            if (blue_in_hole) continue;
            if (red_in_hole) {
                cout << cur.cnt + 1 << '\n';
                return 0;
            }

            // 
            if (nrx == nbx && nry == nby) {
                int red_dist = abs(nrx - cur.rx) + abs(nry - cur.ry);
                int blue_dist = abs(nbx - cur.bx) + abs(nby - cur.by);

                if(red_dist > blue_dist) {
                    nrx -= dx[dir];
                    nry -= dy[dir];
                }
                else {
                    nbx -= dx[dir];
                    nby -= dy[dir];
                }
            }

            // Move Next
            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = true;
                Q.push({nrx, nry, nbx, nby, cur.cnt + 1});
            }            
        }
    }

    cout << -1 << endl;

    return 0;
}