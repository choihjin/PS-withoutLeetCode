#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int origin = n;
  int cnt = 0;
  for(cnt=1;;cnt++) {
    int ten, one;
    if(n/10 != 0) {
      ten = 
      n = (n%10 * 10) + ((n/10 + n%10) % 10);
    } else {
      n = n*10 + n;
    } 

    if(n == origin) break;
  }
  cout << cnt << "\n";
}