#include <bits/stdc++.h>
using namespace std;

long long d[105];
int n, t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[1] = 1, d[2] = 1, d[3] = 1;
    d[4] = 2, d[5] = 2;
    for(int i=6; i<=100; i++) 
        d[i] = d[i-5] + d[i-1];
    
    cin >> t;
    while(t--) {
        cin >> n;
        cout << d[n] << "\n";
    }
}