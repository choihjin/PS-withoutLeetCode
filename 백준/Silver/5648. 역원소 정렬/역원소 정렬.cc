#include <bits/stdc++.h>
using namespace std;

long long arr[1000002];
int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  string buffer;
  for(int i=0; i<n; i++) {
    cin >> buffer;
    reverse(buffer.begin(), buffer.end());
    arr[i] = stoll(buffer);
  }
  
  sort(arr, arr+n);
  for(int i=0; i<n; i++) cout << arr[i] << "\n";
}