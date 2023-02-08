#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans[10];
int arr[10];
bool isused[10];

void func(int k) {
    if(k == m) {
        for(int i=0; i<m; i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=1; i<=n; i++) {
        if(!isused[i]) {
            isused[i] = 1;
            ans[k] = arr[i-1];
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    func(0);
}