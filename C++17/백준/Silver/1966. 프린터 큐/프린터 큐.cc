#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int t;
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        deque<pair<int, int>> Q;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            Q.push_back({tmp, i});
        }

        deque<pair<int, int>> tmp(Q);
        sort(tmp.begin(), tmp.end());

        int cnt = 1;
        while(1) {
            auto cur = Q.front(); Q.pop_front();
            auto high = tmp.back();

            if (high.first > cur.first) {
                Q.push_back(cur);
                continue;
            }
            
            if (cur.second == m) break;
            tmp.pop_back();
            cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}