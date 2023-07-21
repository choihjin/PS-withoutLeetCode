#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int h, w, n;
    cin >> t;
    
    while(t--) {
        int res = 0;
        cin >> h >> w >> n;
        if(n % h == 0) {
            res += 100 * h;
            res += n / h;
        }
        else {
            res += 100 * (n % h);
            res += n / h + 1;
        }
        cout << res << "\n";
    }
}