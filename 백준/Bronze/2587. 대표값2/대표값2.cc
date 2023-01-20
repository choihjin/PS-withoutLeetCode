#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    int n = 5;
    int sum = 0;
    while(n--) {
        int buffer;
        cin >> buffer;
        v.push_back(buffer);
        sum += buffer;
    }
    sort(v.begin(), v.end());
    cout << sum/5 << "\n";
    cout << v[2] << "\n";

    return 0;
}