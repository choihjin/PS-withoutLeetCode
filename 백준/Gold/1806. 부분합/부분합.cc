#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef long long ll;
int n, s;
int arr[100002];
ll sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(int i = 0; i < n; i++) 
        cin >> arr[i];

    int r = 0;
    sum = arr[0];
    int ans = 100002;
    for(int l = 0; l < n; l++) {
        while(sum < s && r < n) 
            sum += arr[++r];
        
        if(sum >= s) 
            ans = min(ans, r - l + 1);
        
        sum -= arr[l];
    }

    if(ans == 100002) ans = 0;
    cout << ans << endl;

    return 0;
}