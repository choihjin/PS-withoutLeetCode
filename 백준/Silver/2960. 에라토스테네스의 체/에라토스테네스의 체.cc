#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i=2; i<=n; i++) v.push_back(i);

    int cnt = 1;
    while(!v.empty()) {
        int cur = v[0];
        for(int i=cur; i<=n; i+=cur) {
            auto pt = find(v.begin(), v.end(), i);
            // cout << cur << " " << i << " " << *pt << endl;
            if(pt != v.end()) {
                v.erase(find(v.begin(), v.end(), i));
                if(cnt++ == k) {
                    cout << i << endl;
                    return 0;
                }
            }
        }
    }
}