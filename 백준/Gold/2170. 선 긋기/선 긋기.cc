#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define X first
#define Y second

int n;
vector<pair<int, int>> lines;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        lines.push_back({x, y});
    }
    sort(lines.begin(), lines.end());
    
    int ans = 0;
    pair<int, int> prev = lines[0];
    for(int i=1; i<n; i++) {
        pair<int, int> cur = lines[i];
        if(prev.Y >= cur.X && prev.Y <= cur.Y) prev.Y = cur.Y;
        else if(cur.X > prev.Y) {
            ans += prev.Y - prev.X;
            prev.X = cur.X;
            prev.Y = cur.Y;
        }
    }

    cout << ans + prev.Y - prev.X << endl;

    return 0;
}