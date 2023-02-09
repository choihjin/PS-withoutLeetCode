#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<10; i++) {
        cout << n << " * " << i << " = " << n*i <<"\n";
    }
}