#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int target;
  bool occur[2000001];
  int arr[1000001]={};
  int count = 0;

  cin >> n;
  for(int i=0; i<n; i++) cin >> arr[i];
  cin >> target;

  for(int i=0; i<n; i++) {
    if(target-arr[i] > 0 && occur[target-arr[i]]) {
      count++;
    }
    occur[arr[i]] = true;
  }

  cout << count << "\n";
  return 0;
}