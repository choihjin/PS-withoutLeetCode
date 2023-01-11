#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  while(n != 1) {
    for(int i=2; i<=n; i++) {
      if(n % i == 0) {
        cout << i << endl;
        n /= i;
        break;
      }
    }
  }
  return 0;
}