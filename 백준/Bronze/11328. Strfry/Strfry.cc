#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  
  while(n--) {
    string a, b;
    cin >> a >> b;

    // 두 문자열의 알파벳 개수 저장하는 배열
    int arr[26] = {0, };
    int arr2[26] = {0, };
    
    // 사이즈가 다르면 False
    if(a.size() != b.size()) {
      cout << "Impossible\n";
      continue;
    } 
    // 알파벳 개수를 카운트해서 비교
    else {
      for(int i=0; i<a.size(); i++) {
        arr[a[i]-'a']++;
        arr2[b[i]-'a']++;
      }
    
      bool isPossible = true;
      for(int i=0; i<26; i++) {
        if(arr[i] != arr2[i]) {
          isPossible = false;
          break;
        }
      }
      if(isPossible) cout << "Possible\n";
      else cout << "Impossible\n";
    }
  }
}