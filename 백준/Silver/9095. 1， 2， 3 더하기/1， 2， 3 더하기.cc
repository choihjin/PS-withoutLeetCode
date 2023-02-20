#include <bits/stdc++.h>
using namespace std;

int D[15];
int t, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    D[1] = 1, D[2] = 2, D[3] = 4; // 초기값 설정
    for(int i=4; i<12; i++) 
        D[i] = D[i-1] + D[i-2] + D[i-3];
    
    while(t--) {
        cin >> n;
        cout << D[n] << "\n";
    }
}