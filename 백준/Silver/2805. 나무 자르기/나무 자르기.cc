#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef long long ll;
int n, m;
int arr[1000002];

bool solve(ll x) {
    ll cur = 0;
    for(int i = 0; i < n; i++) 
        if(arr[i] > x) cur += arr[i] - x;
    return cur >= m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
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