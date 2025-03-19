#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define INF 1e9

int dp[100002][5][5];

int cost(int from, int to) {
    if(from == 0) return 2;
    if(from == to) return 1;
    if(abs(from - to) == 2) return 4;
    return 3;    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(&dp[0][0][0], &dp[100002][0][0], INF);
    dp[0][0][0] = 0;
    
    int nxt, step = 0;
    while(1) {
        cin >> nxt;
        if(nxt == 0) break;

        for(int l = 0; l < 5; l++) {
            for(int r = 0; r < 5; r++) {
                if(dp[step][l][r] == INF) continue;

                dp[step+1][nxt][r] = min(dp[step+1][nxt][r], dp[step][l][r] + cost(l, nxt));
                dp[step+1][l][nxt] = min(dp[step+1][l][nxt], dp[step][l][r] + cost(r, nxt));
            }
        }

        step++;
    }

    int ans = INF;
    for (int l = 0; l < 5; l++)
        for (int r = 0; r < 5; r++)
            ans = min(ans, dp[step][l][r]);

    cout << ans << endl;

    return 0;
}