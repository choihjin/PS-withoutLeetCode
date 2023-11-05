#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int arr[102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<n; i++) 
        arr[i] = i+1;

    while(m--) {
        int i, j;
        cin >> i >> j;
        reverse(arr+i-1, arr+j);
    }

    for(int i=0; i<n; i++) 
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}