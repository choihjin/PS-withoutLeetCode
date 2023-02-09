#include <bits/stdc++.h>
using namespace std;

int n;
int arr[15];
int ans[15];
bool isused[15];

void func(int k) {
  if(k == 6) {
    for(int i=0; i<6; i++) cout << ans[i] << " ";
    cout << "\n";
    return;
  }
  
  for(int i=0; i<n; i++) {
    if(!isused[i]) {
      if(k != 0 && ans[k-1] > arr[i]) continue;
      isused[i] = 1;
      ans[k] = arr[i];
      func(k+1);
      isused[i] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(1) {
    cin >> n;
    if(n == 0) break;
    for(int i=0; i<n; i++) cin >> arr[i];
    func(0);
    cout << "\n";
  }
}