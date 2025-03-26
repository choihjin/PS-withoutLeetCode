#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;
pair<int, int> arr[102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+n);

    vector<int> tail;
    for(int i = 0; i < n; i++) {
        auto iter = lower_bound(tail.begin(), tail.end(), arr[i].second);

        if(iter == tail.end()) tail.push_back(arr[i].second);
        else *iter = arr[i].second;
    }

    cout << n - tail.size() << endl;

    return 0;
}