#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

int n;
vector<pair<int, int>> flower;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> flower;
    for (int i = 0; i < n; i++) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        flower.push_back({sm * 100 + sd, em * 100 + ed});
    }

    int t = 301; // current time
    int ans = 0; // the # of selected flowers
    while (t < 1201) {
        int nxt_t = t; 
        for(int i = 0; i < n; i++){
        if(flower[i].X <= t && flower[i].Y > nxt_t)
            nxt_t = flower[i].Y;
        }
        if(nxt_t == t){ // impossible case
        cout << 0 << endl;;
        return 0;
        }
        ans++;
        t = nxt_t;
    }
    cout << ans << endl;
}