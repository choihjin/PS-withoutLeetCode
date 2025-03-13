#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int left = 0, right = n - 1;
    int diff = INT_MAX;
    pair<int, int> ans;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < diff) {
            diff = abs(sum);
            ans = {arr[left], arr[right]};
        }

        if (sum < 0) left++;
        else right--;
    }

    cout << ans.first << " " << ans.second << endl;
    return 0;
}