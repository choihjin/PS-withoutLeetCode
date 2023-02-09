#include <bits/stdc++.h>
using namespace std;

int n, m;
char arr[20];
char ans[20];
bool isused[20];

void func(int k) {
  if(k == m) {
    int con = 0; // 자음
    int vowel = 0; // 모음
    
    for(int i=0; i<m; i++) {
      if(ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') vowel++;
      else con++;
    }

    if(vowel >= 1 && con >= 2) {
      for(int i=0; i<m; i++) cout << ans[i];
      cout << "\n";
    }
    
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

  cin >> m >> n;
  for(int i=0; i<n; i++) cin >> arr[i];
  sort(arr, arr+n);
  func(0);
}