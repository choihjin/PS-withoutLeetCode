#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef long long ll;
int n;
ll arr[5002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    ll tmp = LLONG_MAX;
    vector<int> ans(3);
    for(int i = 0; i < n; i++) {
        ll st = i+1;
        ll en = n-1;
        while(st < en) {
            ll sum = arr[i] + arr[st] + arr[en];
            if(abs(sum) < tmp) {
                // cout << st << " " << en << endl; 
                ans[0] = arr[i];
                ans[1] = arr[st];
                ans[2] = arr[en];
                tmp = abs(sum);
            }
            
            if(sum > 0) en--;
            else st++;
        }
    }

    sort(ans.begin(), ans.end());
    for(auto a : ans) cout << a << " ";
    cout << endl;

    return 0;
}