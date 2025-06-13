#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef long long ll;
int n;
int sour[12], bitter[12];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> sour[i] >> bitter[i];
    }

    ll diff = 0x7f7f7f7f;
    for(int mask = 1; mask < (1 << n); mask++) {
        ll cur_sour = 1, cur_bitter = 0;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                cur_sour *= sour[i];
                cur_bitter += bitter[i];
            }
        }

        ll cur_diff = abs(cur_sour - cur_bitter);
        if(diff > cur_diff) diff = cur_diff;
    }

    cout << diff << endl;

    return 0;
}