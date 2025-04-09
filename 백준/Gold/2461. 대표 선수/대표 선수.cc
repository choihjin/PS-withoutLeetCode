#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

priority_queue<
    tuple<int, int, int>, 
    vector<tuple<int, int, int>>, 
    greater<tuple<int, int, int>>
> pq;

int n, m;
int students[1002][1002];
int mx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> students[i][j];
        }
        sort(students[i], students[i] + m);
        pq.push({students[i][0], i, 0});
        mx = max(mx, students[i][0]);
    }

    int ans = 0x7fffffff;
    while(1) {
        int value, school, idx;
        tie(value, school, idx) = pq.top(); pq.pop();

        ans = min(ans, mx - value);

        if(idx == m - 1) break;

        pq.push({students[school][idx+1], school, idx+1});
        mx = max(mx, students[school][idx+1]);
    }

    cout << ans << endl;

    return 0;
}