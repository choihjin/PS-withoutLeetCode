#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef long long ll;
int n;
ll a[4002], b[4002], c[4002], d[4002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    vector<ll> ab, cd;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }
    sort(cd.begin(), cd.end());

    ll ans = 0;
    for(auto a : ab) {
        auto lb = lower_bound(cd.begin(), cd.end(), -a);
        auto ub = upper_bound(cd.begin(), cd.end(), -a);
        ans += ub - lb;
    }

    cout << ans << endl;

    return 0;
}