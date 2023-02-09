#include <bits/stdc++.h>
using namespace std;

int sum, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> sum >> n;
    int ans = 0;
    while(n--) {
        int buffer;
        int cnt;
        cin >> buffer >> cnt;
        ans += buffer * cnt;
    }
    
    if(sum == ans) cout << "Yes";
    else cout << "No";
}