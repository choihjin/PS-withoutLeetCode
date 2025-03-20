#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m;
int arr[2002];
int dp[2002][2002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i][i] = 1;
    }
    
    for(int i = 1; i < n; i++)
        if(arr[i] == arr[i+1]) dp[i][i+1] = 1;

    for(int len = 3; len <= n; len++) {
        for(int i = 1; i <= n; i++) {
            int j = i + len - 1;
            if(arr[i] == arr[j] && dp[i+1][j-1]) dp[i][j] = 1;
        }
    }

    cin >> m;
    while(m--) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << endl;
    }

    return 0;
}