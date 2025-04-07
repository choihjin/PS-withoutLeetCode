#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
int arr[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    ll ans = 0;
    int l = 0;
    unordered_set<int> s;

    for (int r = 0; r < n; r++) {
        while (s.count(arr[r])) {
            s.erase(arr[l]);
            l++;
        }
        s.insert(arr[r]);
        ans += (r - l + 1);
    }

    cout << ans << '\n';
    return 0;
}
