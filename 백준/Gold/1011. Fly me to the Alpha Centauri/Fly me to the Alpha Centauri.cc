#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll x, y;
        cin >> x >> y;
        
        int ans = 0;
        int pos = 0;
        int sum = 0;
        while(x < y) {
            // pos + 1 case
            if(x + sum + pos+1 <= y) {
                pos++;
                ans++;
                x += pos;
                if(pos >= 1) sum += pos;
            }
            // pos case
            else if(x + sum <= y) {
                ans++;
                x += pos;
            }
            // pos - 1 case
            else {
                ans++;
                if(sum > 1) sum -= pos;
                if(pos != 1) pos--;
                x += pos;
            }
        }
        cout << ans << endl;
    }
}