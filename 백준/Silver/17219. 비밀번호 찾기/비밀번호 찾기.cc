#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m;
unordered_map<string, string> memo;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while(n--) {
        string a, b;
        cin >> a >> b;
        memo[a] = b;
    }

    while(m--) {
        string a;
        cin >> a;
        cout << memo[a] << endl;
    }

    return 0;
}