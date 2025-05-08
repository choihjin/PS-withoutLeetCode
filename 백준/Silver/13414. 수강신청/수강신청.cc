#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int k, l;
unordered_map<string, int> signup;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> l;
    for(int i = 0; i < l; i++) {
        string tmp;
        cin >> tmp;
        signup[tmp] = i;
    }
    
    vector<pair<string, int>> tmp (signup.begin(), signup.end());
    sort(tmp.begin(), tmp.end(), [](auto &a, auto &b){return a.second < b.second;});

    int en = min(k, (int)tmp.size());
    for(int i = 0; i < en; i++) 
        cout << tmp[i].first << endl;

    return 0;
}