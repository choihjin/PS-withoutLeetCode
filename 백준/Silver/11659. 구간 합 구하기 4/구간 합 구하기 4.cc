#include <bits/stdc++.h>
using namespace std;

int D[100002];
int A[100002];
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> A[i];

    D[1] = A[1];
    for(int i=2; i<=n; i++) D[i] = D[i-1] + A[i];

    while(m--) {
        int i, j;
        cin >> i >> j;
        cout << D[j]-D[i-1] << "\n";
    }
}