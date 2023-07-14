#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    vector<int> res;
    for(int i=0; i<n; i++) 
        v[i] = i+1;
    
    int cur = k-1;
    res.push_back(v[cur]);
    v.erase(v.begin() + cur);
    n--;

    while(n) {
        cur = (cur + k-1) % n;
        res.push_back(v[cur]);
        v.erase(v.begin() + cur);
        n--;
    }
    
    cout << "<";
    for(int i =0; i<res.size(); i++) {
        if(i == res.size() - 1) cout << res[i];
        else cout << res[i] << ", ";
    }
    cout << ">\n";

    return 0;
}