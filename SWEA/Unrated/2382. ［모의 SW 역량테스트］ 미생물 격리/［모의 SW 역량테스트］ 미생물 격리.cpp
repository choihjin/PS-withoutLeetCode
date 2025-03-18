#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

struct Microbe {
    int x, y, count, dir;
};

int N, M, K; // 맵 크기, 시간, 군집 개수
vector<Microbe> microbes;
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};
int dir_reverse[5] = {0, 2, 1, 4, 3};

void solution() {
    while (M--) {
        unordered_map<int, vector<Microbe>> cellMap;
        
        for (auto &m : microbes) {
            m.x += dx[m.dir];
            m.y += dy[m.dir];

            // Red area
            if (m.x == 0 || m.x == N - 1 || m.y == 0 || m.y == N - 1) {
                m.count /= 2;
                m.dir = dir_reverse[m.dir];
            }

            // Grouping
            int key = m.x * 100 + m.y;
            cellMap[key].push_back(m);
        }

        // Merging
        microbes.clear();
        for (auto &p : cellMap) {
            int key = p.first;
            vector<Microbe> &group = p.second;

            if (group.size() == 1)
                microbes.push_back(group[0]);
            else {
                sort(group.begin(), group.end(), [](Microbe &a, Microbe &b) {
                    return a.count > b.count;
                }); // descending order

                int total = 0;
                for (auto &m : group) total += m.count;

                microbes.push_back({group[0].x, group[0].y, total, group[0].dir});
            }
        }
    }
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> M >> K;

        microbes.clear();
        for (int i = 0; i < K; i++) {
            int tx, ty, tc, td;
            cin >> tx >> ty >> tc >> td;
            microbes.push_back({tx, ty, tc, td});
        }

        solution();

        int ans = 0;
        for (auto &m : microbes) ans += m.count;

        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}