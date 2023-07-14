#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cur;
    double gg, gb, bg, bb;
    vector<double> good, bad;
    
    cin >> n >> cur;
    cin >> gg >> gb >> bg >> bb;
    
    if (cur == 0) {
        good.push_back(gg);
        bad.push_back(gb);
    }
    else {
        good.push_back(bg);
        bad.push_back(bb);
    }
    for (int i = 1; i < n; i++) {
        good.push_back(good[i-1] * gg + bad[i-1] * bg);
        bad.push_back(good[i-1] * gb + bad[i-1] * bb);
    }

    cout << fixed;
    cout.precision(0);
    cout << good[n-1] * 1000 << '\n' << bad[n-1] * 1000 << "\n";

    return 0;
}