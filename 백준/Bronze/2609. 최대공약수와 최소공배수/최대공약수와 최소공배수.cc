#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int gcd(int a, int b) {
    if(a < b) swap(a,b);
    int c = a % b;
    while(c!=0) {
        a = b;
        b = c;
        c = a % c;
    }
    return b;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    cout << gcd(n,m) << endl;
    cout << lcm(n,m) << endl;

    return 0;
}