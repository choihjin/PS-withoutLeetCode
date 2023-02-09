#include <bits/stdc++.h>
using namespace std;

int n;
double arr[1002];
double sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
  
    sort(arr, arr+n);
  
    for(int i=0; i<n; i++) {
      sum += (arr[i]/arr[n-1]) * 100;
    }

    cout << sum / n << "\n";
}