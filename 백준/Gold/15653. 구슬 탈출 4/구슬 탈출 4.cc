#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// 현재 R, B 구슬의 위치와 이동 횟수를 저장하는 구조체
struct State {
    int rx, ry; // R 위치
    int bx, by; // B 위치
    int cnt;    // 움직인 횟수
};

int n, m;
string board[12];
bool visited[12][12][12][12]; // [rx][ry][bx][by] 상태 기록
queue<State> Q;

int dx[4] = {0, 0, -1, 1}; // → ← ↑ ↓
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
    visited[tmp.rx][tmp.ry][tmp.bx][tmp.by] = true;

    while(!Q.empty()) {
        State cur = Q.front(); Q.pop();

        // if (cur.cnt >= 10) continue; // 10번 초과 금지

        for (int dir = 0; dir < 4; dir++) {
            int nrx = cur.rx, nry = cur.ry;
            int nbx = cur.bx, nby = cur.by;

            bool red_in_hole = false, blue_in_hole = false;

            // R 이동
            while (board[nrx + dx[dir]][nry + dy[dir]] != '#' && board[nrx][nry] != 'O') {
                nrx += dx[dir];
                nry += dy[dir];
                if (board[nrx][nry] == 'O') red_in_hole = true;
            }

            // B 이동
            while (board[nbx + dx[dir]][nby + dy[dir]] != '#' && board[nbx][nby] != 'O') {
                nbx += dx[dir];
                nby += dy[dir];
                if (board[nbx][nby] == 'O') blue_in_hole = true;
            }

            // 파란 구슬이 빠졌으면 실패
            if (blue_in_hole) continue;

            // 빨간 구슬만 빠졌으면 성공
            if (red_in_hole) {
                cout << cur.cnt + 1 << '\n';
                return 0;
            }

            // R과 B가 같은 칸에 있는 경우 -> 더 멀리 온 구슬 한 칸 뒤로
            if (nrx == nbx && nry == nby) {
                int red_dist = abs(nrx - cur.rx) + abs(nry - cur.ry);
                int blue_dist = abs(nbx - cur.bx) + abs(nby - cur.by);

                if (red_dist > blue_dist) {
                    nrx -= dx[dir];
                    nry -= dy[dir];
                } else {
                    nbx -= dx[dir];
                    nby -= dy[dir];
                }
            }

            // 새로운 상태가 방문되지 않았으면 큐에 넣기
            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = true;
                Q.push({nrx, nry, nbx, nby, cur.cnt + 1});
            }
        }
    }

    cout << -1 << endl; // 10번 안에 성공 못하면 실패
    return 0;
}