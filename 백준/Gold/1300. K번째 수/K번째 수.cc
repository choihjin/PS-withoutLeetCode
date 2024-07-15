#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

ll res;

void solution(int n, int k, ll lo, ll hi) {
    ll val = (lo + hi) / 2, smalls = 0, tmp;

    for(ll layer = 1; layer <= n; layer++) {
        tmp = val / layer;
        if(tmp > n) tmp = n;
        smalls += tmp;
    }

    if(lo == hi) {res = lo; return;}

    if(smalls < k)
        solution(n, k, val+1, hi);
    else
        solution(n, k, lo, val);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n, k;
    cin >> n >> k;

    solution(n, k, 1, n*n);
    
    cout << res << endl;
    return 0;
} 