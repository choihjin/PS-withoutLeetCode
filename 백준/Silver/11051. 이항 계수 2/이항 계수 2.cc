#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int dp[1002][1002];

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=k; j++) {
            if (j == 0 || i == j) dp[i][j] = 1;
			else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}