#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int t, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        unordered_map<string, int> clothings;
        cin >> n;

        while(n--) {
            string a, b;
            cin >> a >> b;
            clothings[b]++;
        }

        int ans = 1;
        for (auto v : clothings) ans *= v.second + 1;
        cout << ans - 1 << endl; 
    }

    return 0;
}