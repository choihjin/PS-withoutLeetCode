#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[1000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0;
    int skip = 0;
    int l = 0, r = 0;

    while(r < n) {
        if(arr[r] % 2 == 0) {
            r++;
        } else {
            if(skip < k) {
                skip++;
                r++;
            } else {
                if(arr[l] % 2 == 1) skip--;
                l++;
            }
        }
        ans = max(ans, r - l - skip);  // 현재 윈도우에서 홀수 제거하고 남은 짝수 수의 길이
    }

    cout << ans << '\n';

    return 0;
}
