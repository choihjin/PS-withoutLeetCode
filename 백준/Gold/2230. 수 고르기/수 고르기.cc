#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;
int arr[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    ll ans = 0x7fffffff;
    int st = 0, en = 0;
    while(st != n - 1 && en < n) {
        ll diff = arr[en] - arr[st];
        if(diff < m) en++;
        else {
            ans = min(ans, diff);
            st++;
        }
    }

    cout << ans << endl;

    return 0;
}