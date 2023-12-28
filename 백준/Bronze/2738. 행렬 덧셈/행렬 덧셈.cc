#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int arr1[102][102];
int arr2[102][102];
int sum[102][102];
int  n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) 
            cin >> arr1[i][j];

    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) 
            cin >> arr2[i][j];

    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) 
            sum[i][j] = arr1[i][j] + arr2[i][j];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cout << sum[i][j] << " ";
        cout << "\n";
    }

    return 0;
}