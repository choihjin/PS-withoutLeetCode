#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int n[1002];

int main() {
    int a, b;
    cin >> a >> b;

    int idx = 1;
    for(int i=1; idx<=b; i++) {
        for(int j=0; j<i; j++) {
            n[idx] = i;
            idx++;
        }
    }

    int sum = 0;
    for(int i=a; i<=b; i++) 
        sum += n[i];
        
    cout << sum << endl;
}