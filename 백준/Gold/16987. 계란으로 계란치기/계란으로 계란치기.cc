#include <bits/stdc++.h>
using namespace std;

int n;
int s[10], w[10];
int mx = 0;
int cnt = 0; // 깨져있는 계란의 수

void func(int k) {
    if(k == n) {
        mx = max(mx, cnt);
        return;
    } // 가장 오른쪽 계란에 도착했을 때

    if(s[k] <= 0 || cnt == n-1) {
        func(k+1);
        return;
    } // k번째 계란이 깨져있거나 다른 모든 계란이 깨져있으면 패스

    // 백트래킹
    for(int i=0; i<n; i++) {
        if(i == k || s[i] <= 0) continue;
        s[k] -= w[i];
        s[i] -= w[k];
        if(s[k] <= 0) cnt++;
        if(s[i] <= 0) cnt++;

        func(k+1);

        if(s[k] <= 0) cnt--;
        if(s[i] <= 0) cnt--;
        s[k] += w[i];
        s[i] += w[k];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> s[i] >> w[i];
    func(0);
    cout << mx << "\n";
}