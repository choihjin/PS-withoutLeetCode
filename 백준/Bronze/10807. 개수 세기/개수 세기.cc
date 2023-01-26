#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, v;
  int arr[101];
  
  cin >> n;
  for(int i=0; i<n; i++) cin >> arr[i];
  cin >> v;

  int count = 0;
  for(int i=0; i<n; i++) if(arr[i] == v) count++;

  cout << count << endl;
}