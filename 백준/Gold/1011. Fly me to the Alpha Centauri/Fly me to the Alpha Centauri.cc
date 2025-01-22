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
            // cout << "x : " << x << " ans : " << ans << " pos : " << pos << " sum : " << sum << endl;
            // pos + 1 case
            if(x + sum + pos+1 <= y) {
                pos++;
                // cout << "pos+1 case : +" << pos << endl;
                ans++;
                x += pos;
                if(pos >= 1) sum += pos;
            }
            // pos case
            else if(x + sum <= y) {
                // cout << "pos case : +" << pos << endl;
                ans++;
                x += pos;
            }
            // pos - 1 case
            else {
                // cout << "pos-1 case : +" << pos-1 << endl;
                ans++;
                if(sum > 1) sum -= pos;
                if(pos != 1) pos--;
                x += pos;
            }
        }
        // cout << "x : " << x << " ans : " << ans << " pos : " << pos << " sum : " << sum << endl;
        cout << ans << endl;
    }
}