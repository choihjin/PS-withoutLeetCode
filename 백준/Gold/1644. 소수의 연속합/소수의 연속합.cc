#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> primes;
    vector<bool> state(n+1, true);
    for(int i = 2; i * i <= n; i++) {
        if(!state[i]) continue;
        for(int j = i * i; j <= n; j += i) 
            state[j] = false;
    }
    for(int i = 2; i <= n; i++) 
        if(state[i]) 
            primes.push_back(i);

    int l = 0, r = 0;
    ll sum = (primes.empty() ? 0 : primes[0]);
    int ans = 0;
    while(l < primes.size() && r < primes.size()) {
        if(sum < n) {
            r++;
            if (r < primes.size()) sum += primes[r];
        }
        else {
            if(sum == n) ans++;
            sum -= primes[l++];
        }
    }

    cout << ans << endl;

    return 0;
}