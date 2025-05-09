#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;
int arr[2002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int l = 0, r = n-1;
        while(l < r) {
            if(l == i) l++;
            else if(r == i) r--;

            if(arr[l] + arr[r] == arr[i] && l != i && r != i && l != r) {
                ans++;
                break;
            }
            else if(arr[l] + arr[r] < arr[i]) l++;
            else r--;
        }
    }

    cout << ans << endl;

    return 0;
}