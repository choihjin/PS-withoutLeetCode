#include <bits/stdc++.h>
using namespace std;

int arr[1000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=2; i<=m; i++)
        arr[i] = i;

    for(int i=2; i*i<=m; i++) {
        if(!arr[i]) continue;
        
        for(int j=i*i; j<=m; j+=i) 
            arr[j] = 0;
    }

    for(int i=n; i<=m; i++) 
        if(arr[i]) cout << i << "\n";
        
    return 0;
}