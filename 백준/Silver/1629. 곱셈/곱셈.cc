#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll pow(ll a, ll b ,ll c) {
    if(b == 1) return a % c; // base condition
    ll val = pow(a, b/2, c);
    val = val * val % c;
    if(b % 2 == 0) return val;
    return val * a % c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, b, c) << "\n";
}