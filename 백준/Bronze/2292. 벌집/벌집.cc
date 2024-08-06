#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

long long n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if(n==1) {
        cout << 1 << endl;
        return 0;
    }

    int ans = 1, cur = 2;
    for(int i=1; ;i++) {
        ans++;
        if(n >= cur && n < cur + i*6) break;
        cur += i*6;
    }
    cout << ans << endl;
}