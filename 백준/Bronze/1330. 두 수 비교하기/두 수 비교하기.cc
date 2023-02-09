#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >>m;
  if(n > m) {
      cout << ">";
  } else if(n < m) {
      cout << "<";
  } else {
      cout << "==";
  }
}