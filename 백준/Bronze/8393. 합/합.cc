#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    int sum = 0;
    for(int i=1; i<=n; i++) sum+=i;
    cout << sum;
}