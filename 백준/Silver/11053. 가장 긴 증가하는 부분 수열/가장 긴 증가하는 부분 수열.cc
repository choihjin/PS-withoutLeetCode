#include <bits/stdc++.h>
using namespace std;

int d[1005];
int a[1005];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        d[i] = 1;
    }

    for(int i=0; i<n; i++) {
        int mx = 0;
        for(int j=0; j<i; j++) 
            if(a[j] < a[i]) 
                mx = max(mx, d[j]);
        d[i] = mx + 1;
    }

    cout << *max_element(d, d+n);
}