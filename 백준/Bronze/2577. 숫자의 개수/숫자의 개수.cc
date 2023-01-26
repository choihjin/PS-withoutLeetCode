#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int arr[10] = {0,};
  int a, b, c;
  cin >> a >> b >> c;

  string s = to_string(a*b*c);

  for(char c : s) {
    arr[c-'0']++;
  }

  for(int i=0; i<10; i++) cout << arr[i] << "\n";
  
  return 0;
}