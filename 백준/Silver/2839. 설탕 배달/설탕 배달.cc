#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;
int a[5005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(a, a+n+1, -1);
    a[3] = 1; a[5] = 1;
    for(int i=6; i<=n; i++) {
        if(a[i-3] == -1 && a[i-5] == -1) continue;
        else if(a[i-5] != -1) a[i] = a[i-5]+1;
        else if(a[i-3] != -1) a[i] = a[i-3]+1;
    }

    cout << a[n] << endl;
}