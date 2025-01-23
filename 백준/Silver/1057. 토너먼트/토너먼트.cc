#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int round = 0;
    while(a != b) {
        a = ceil(a / 2.0);
        b = ceil(b / 2.0);
        round++;
    }
    cout << round << endl;
}