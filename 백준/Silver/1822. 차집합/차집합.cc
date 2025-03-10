#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int na, nb;
int a[500002], b[500002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> na >> nb;
    for(int i=0; i<na; i++) cin >> a[i];
    for(int i=0; i<nb; i++) cin >> b[i];
    sort(a, a+na);
    sort(b, b+nb);

    vector<int> ans;
    for(int i=0; i<na; i++) {
        if(!binary_search(b, b+nb, a[i])) ans.push_back(a[i]);
    }

    cout << ans.size() << endl;
    for(auto element : ans) cout << element << " ";

    return 0;
}