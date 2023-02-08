#include <bits/stdc++.h>
using namespace std;

int n, s, cnt = 0;
int arr[30];

void func(int cur, int tot) { 
    if(cur == n) {
        if(tot == s) cnt++;
        return;
    }

    func(cur+1, tot); // 패스하는 경우
    func(cur+1, tot+arr[cur]); // 더하는 경우
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(int i=0; i<n; i++) cin >> arr[i];

    func(0, 0);
    if(s == 0) cnt--; // 공집합 제외
    cout << cnt << "\n";
}