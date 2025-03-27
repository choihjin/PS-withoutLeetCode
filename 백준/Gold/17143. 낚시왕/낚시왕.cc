#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

struct Shark {
    int x, y, s, d, z;
};
int r, c, m;
Shark shark[10002];
int sea[102][102];

int dx[5] = {0, 0, 0, 1, -1};  // 1~4: dummy, left-right-down-up
int dy[5] = {0, -1, 1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> m;

    for (int i = 1; i <= c; i++)
        fill(sea[i] + 1, sea[i] + r + 1, -1);

    for (int i = 0; i < m; i++) {
        int y, x, s, d, z;
        cin >> y >> x >> s >> d >> z;
        shark[i] = {x, y, s, d, z};
        sea[x][y] = i;
    }

    int ans = 0;
    int cur = 0;

    for (int t = 0; t < c; t++) {
        cur++;

        // 1. 낚시
        for (int i = 1; i <= r; i++) {
            int idx = sea[cur][i];
            if (idx != -1) {
                ans += shark[idx].z;
                shark[idx].z = -1;
                sea[cur][i] = -1;
                break;
            }
        }

        // 2. 상어 이동
        int temp[102][102];
        for (int i = 1; i <= c; i++)
          fill(temp[i] + 1, temp[i] + r + 1, -1);

        for (int i = 0; i < m; i++) {
            if (shark[i].z == -1) continue;

            int x = shark[i].x;
            int y = shark[i].y;
            int s = shark[i].s;
            int d = shark[i].d;
            int z = shark[i].z;

            // 속도 줄이기
            if (d == 1 || d == 2) s %= (r - 1) * 2;
            else s %= (c - 1) * 2;

            for (int j = 0; j < s; j++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (ny < 1 || ny > r || nx < 1 || nx > c) {
                    if(d % 2 == 0) d--;
                    else d++;
                    nx = x + dx[d];
                    ny = y + dy[d];
                }
                x = nx;
                y = ny;
            }

            // 이동 결과 반영
            if (temp[x][y] == -1) {
                temp[x][y] = i;
                shark[i] = {x, y, s, d, z};
            } else {
                int other = temp[x][y];
                if (shark[other].z < z) {
                    shark[other].z = -1;
                    temp[x][y] = i;
                    shark[i] = {x, y, s, d, z};
                } else {
                    shark[i].z = -1;
                }
            }
        }

        // sea 갱신
        memcpy(sea, temp, sizeof(sea));
    }

    cout << ans << endl;

    return 0;
}