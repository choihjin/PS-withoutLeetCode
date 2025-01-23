#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int main() {
    int n;
    cin >> n;
    
    if(n <= 10) cout << n << endl;
    else {
        int cnt = 10;
        for(ll i=11; i<=9876543210; i++) {
            string str = to_string(i);

            int j = 1;
            for(; j<str.size(); j++) 
                if(str[j-1] <= str[j]) break;

            if(j == str.size()) {
                cnt++;
                // cout << i << " " << cnt << endl;
            }
            else {
                ll p = ceil(pow(10, str.size()-j));
                i /= p;
                i++;
                i *= p;
                i--;
            }

            if(cnt == n) {
                cout << i << endl;
                return 0;
            }
        }

        cout << -1 << endl;
    }
}