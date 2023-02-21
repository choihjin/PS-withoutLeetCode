#include <bits/stdc++.h>
using namespace std;

int D[1002][3];
int R[1002], G[1002], B[1002];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> R[i] >> G[i] >> B[i];
    if(n == 1) {
        cout << min(min(R[1], G[1]), B[1]);
        return 0;
    }

    D[1][0] = R[1], D[1][1] = G[1], D[1][2] = B[1]; // 초기값 설정
    for(int k=2; k<=n; k++) {
        D[k][0] = min(D[k-1][1], D[k-1][2]) + R[k];
        D[k][1] = min(D[k-1][0], D[k-1][2]) + G[k];
        D[k][2] = min(D[k-1][0], D[k-1][1]) + B[k];
    }

    cout << min(min(D[n][0], D[n][1]), D[n][2]) << "\n";
}