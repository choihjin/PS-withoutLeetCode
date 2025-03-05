#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int N;
unordered_set<string> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--) {
        string a, b;
        cin >> a >> b;
        if(b == "enter") m.insert(a);
        else m.erase(a);
    }

    vector<string> v(m.begin(), m.end());
    sort(v.begin(), v.end());

    for(int i=v.size()-1; i>=0; i--) {
        cout << v[i] << endl;
    }

    return 0;
}