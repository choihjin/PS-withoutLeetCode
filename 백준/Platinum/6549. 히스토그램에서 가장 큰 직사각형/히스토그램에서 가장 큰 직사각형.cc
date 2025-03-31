#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef long long ll;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        cin >> n;
        if(n == 0) break;

        vector<ll> h(n +1);
        for(int i = 0; i < n; i++) 
            cin >> h[i];
        
        h[n] = 0; // Sentinel

        stack<int> s;
        ll ans = 0; 

        for(int i = 0; i <=n; i++) {
            while(!s.empty() && h[s.top()] > h[i]) {
                int height = h[s.top()];
                s.pop();
                int width = i - (s.empty() ? 0 : s.top() + 1);
                ans = max(ans, (ll)height * width);
            }
            s.push(i);
        }

        cout << ans << endl;
    }

    return 0;
}