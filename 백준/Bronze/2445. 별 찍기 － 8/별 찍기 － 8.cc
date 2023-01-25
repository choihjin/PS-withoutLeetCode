#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<=i; j++) {
      cout << "*";
    }
    for(int j=n-i-1; j>0; j--) {
      cout << " ";
    }
    for(int j=n-1; j>i; j--) {
      cout << " ";
    }
    for(int j=0; j<=i; j++) {
      cout << "*";
    }
    cout << "\n";
  }

  for(int i=0; i<n; i++) {
    for(int j=n-i-1; j>0; j--) {
      cout << "*";
    }
    for(int j=0; j<=i; j++) {
      cout << " ";
    }
    for(int j=0; j<=i; j++) {
      cout << " ";
    }
    for(int j=n-i-1; j>0; j--) {
      cout << "*";
    }
    cout << "\n";
  }
}