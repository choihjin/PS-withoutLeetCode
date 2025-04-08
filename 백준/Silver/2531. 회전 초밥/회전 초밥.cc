#include<bits/stdc++.h>
using namespace std;

int n; // 접시 수
int d; // 초밥 종류
int k; // 연속해서 먹는 접시 수
int c; // 쿠폰 번호
int belt[30002];

#define endl "\n"
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++) cin >> belt[i];

    map<int, int> cnt;
    int unique = 0;

    for (int i = 0; i < k; i++) 
        if (++cnt[belt[i]] == 1) unique++;

    
    int ans = unique + (cnt[c] == 0 ? 1 : 0);

    for (int i = 1; i < n; i++) {
        int out = belt[i - 1];
        int in = belt[(i + k - 1) % n];

        if (--cnt[out] == 0) unique--;
        if (++cnt[in] == 1) unique++;

        int tot = unique + (cnt[c] == 0 ? 1 : 0);
        ans = max(ans, tot);
    }

    cout << ans << endl;

    return 0;
}