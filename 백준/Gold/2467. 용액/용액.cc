#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;
int arr[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int diff = INT_MAX;
    pair<int, int> ans;
    int i = 0;
    for(int i = 0; i < n-1; i++) {
        auto iter = lower_bound(arr, arr+n, -arr[i]);
        if(iter == arr+n) iter--;
        // cout << arr[i] << " " << *iter << endl;

        if(abs(*iter + arr[i]) < diff && *iter != arr[i]) {
            diff = abs(*iter + arr[i]);
            ans = {arr[i], *iter};
        }

        iter = upper_bound(arr, arr+n, -arr[i] - diff);
        if(iter == arr+n) iter--;
        // cout << arr[i] << " " << *iter << endl;

        if(abs(*iter + arr[i]) < diff && *iter != arr[i]) {
            diff = abs(*iter + arr[i]);
            ans = {arr[i], *iter};
        }
        
        iter = upper_bound(arr, arr+n, arr[i]);
        if(iter == arr+n && i != n-1) iter--;
        // cout << arr[i] << " " << *iter << endl;

        if(abs(*iter + arr[i]) < diff && *iter != arr[i]) {
            diff = abs(*iter + arr[i]);
            ans = {arr[i], *iter};
        }

        // cout << diff << endl;
    }

    if(ans.first > ans.second) cout << ans.second << " " << ans.first << endl;
    else cout << ans.first << " " << ans.second << endl;

    return 0;
}