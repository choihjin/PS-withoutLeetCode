#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    int n;
    cin >> n;

    long long fact = 1;
    int ans = 0;
    for(int i=n; i>=2; i--) {
        fact *= i;
        // cout << fact << endl;
        if(fact % 10 == 0) {
            // cout << fact << endl;
            fact /= 10;
            fact %= 100000;
            ans++; 
        }
    }
    cout << ans << endl;
}