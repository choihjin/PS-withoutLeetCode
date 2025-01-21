#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    int cnt = 1;
    while(1) {
        int l, p, v;
        cin >> l >> p >> v;
        if(!l && !p && !v) break;

        int ans = floor(v / p) * l + min(v % p, l);
        cout << "Case " << cnt++ << ": " << ans << endl;
    }
}