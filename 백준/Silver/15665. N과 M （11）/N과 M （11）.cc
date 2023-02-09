#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int ans[10];
int pre; // 백트래킹 했을 때 그 전의 값을 저장해둠

void func(int k) {
  if(k == m) {
    for(int i=0; i<m; i++) cout << ans[i] << " ";
    cout << "\n";
    return;
  }
  
  pre = 0x7f7f7f7f; // k가 바뀌었으면 pre값 초기화
  for(int i=0; i<n; i++) {
    if(pre != arr[i]) {
      ans[k] = arr[i];
      func(k+1);
      pre = arr[i];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i=0; i<n; i++) cin >> arr[i];
  sort(arr, arr+n);
  func(0);
}