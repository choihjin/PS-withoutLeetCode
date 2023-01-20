#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> odd;
    int total = 0;
    int n = 7;
    while(n--) {
        int buffer;
        cin >> buffer;
        if(buffer % 2 == 1) {
            odd.push_back(buffer);
            total += buffer;
        }
    }
    if(odd.size() == 0) cout << -1 << "\n";
    else {
        sort(odd.begin(), odd.end());
        cout << total << "\n";
        cout << odd[0] << "\n";
    }

    return 0;
}