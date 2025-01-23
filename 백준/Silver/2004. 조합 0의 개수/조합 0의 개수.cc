#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int main() {
    ll n, r;
    cin >> n >> r;
    
    int cnt_5 = 0;
    for(ll i=5; i<2000000000; i*=5) {
        cnt_5 += n/i;
        cnt_5 -= r/i;
        cnt_5 -= (n-r)/i;
    }

    int cnt_2 = 0;
    for(ll i=2; i<2000000000; i*=2) {
        cnt_2 += n/i;
        cnt_2 -= r/i;
        cnt_2 -= (n-r)/i;
    }

    cout << min(cnt_2, cnt_5) << endl;
}   