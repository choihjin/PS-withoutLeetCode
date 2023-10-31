#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
    int n, k;
    cin >> n >> k;
    
    if(n == k || k == 0) {
        cout << 1 << endl;
        return 0;
    }

    int n1 = 1;
    for(int i=k+1; i<=n; i++) n1 *= i;
    // cout << n1 << endl;

    int n2 = 1;
    for(int i=1; i<=n-k; i++) n2 *= i;
    // cout << n2 << endl;

    cout << n1/n2 << endl;
    return 0;
}