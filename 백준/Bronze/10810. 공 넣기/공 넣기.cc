#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int arr[102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    while(m--) {
        int i, j, k;
        cin >> i >> j >> k;
        for(int n=i-1; n<j; n++)
            arr[n] = k;
    }

    for(int i=0; i<n; i++) 
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}