#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef long long ll;
int n, c;
int arr[200002];

bool solve(ll x) {
    int cnt = 1;
    int cur = arr[0];
    while(1) {
        auto iter = lower_bound(arr, arr+n, cur+x);
        if(iter == arr+n) break;
        cur = *iter;
        cnt++;
    }

    return cnt >= c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    ll st = 0;
    ll en = arr[n-1];
    while(st < en) {
        ll mid = (st + en + 1) / 2;
        if(solve(mid)) st = mid;
        else en = mid - 1;
    }

    cout << st << endl;

    return 0;
}