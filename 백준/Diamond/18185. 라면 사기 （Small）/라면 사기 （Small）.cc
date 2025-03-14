#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;
int arr[10002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) continue;

        while(arr[i]) {
            if(i < n-2 && arr[i+1] > 0 && arr[i+2] > 0 && arr[i+1] <= arr[i+2]) {
                arr[i]--;
                arr[i+1]--;
                arr[i+2]--;
                ans += 7;
            } 
            else if(i < n-1 && arr[i+1] > 0) {
                arr[i]--;
                arr[i+1]--;
                ans += 5;
            }
            else {
                ans += arr[i] * 3;
                arr[i] = 0;
            }
        }

        // cout << arr[i] << " " << ans << endl;
    }

    cout << ans << endl;

    return 0;
}


// 2 3 2 1
// 1 2 2 1 -> 5
// 0 1 1 1 -> 12
// 0 0 0 0 -> 19
