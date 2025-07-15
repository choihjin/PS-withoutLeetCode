#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int t, k;
int files[502];
int dp[502][502];
int prefix_sum[502];

int sum(int i, int j) {
	return prefix_sum[j] - prefix_sum[i - 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	
	while (t--) {
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> files[i];
			prefix_sum[i] = prefix_sum[i - 1] + files[i];
		}

		// DP[i][j] : i번 파일부터 j번 파일까지를 하나로 합치는 최소 비용
		// DP[i][j] = DP[i][k] + DP[k+1][j] + sum(i, j)
		for (int len = 2; len <= k; len++) {
			for (int i = 1; i <= k - len + 1; i++) {
				int j = i + len - 1;
				dp[i][j] = 0x7f7f7f7f;

				for (int k = i; k < j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum(i, j));
				}
			}
		}

		cout << dp[1][k] << endl;
	}

	return 0;
}
