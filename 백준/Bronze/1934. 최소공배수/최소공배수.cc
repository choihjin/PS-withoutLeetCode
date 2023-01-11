#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  
  for(int i=0; i<t; i++) {
    int a, b;
    cin >> a >> b;
    if(a < b) {
      int temp = a;
      a = b;
      b = temp;
    }
    
    bool check = false;
    int j = 1;
    int buffer;
    while(!check) {
      buffer = a * j;
      if(buffer % b == 0) check = true;
      j++;
    }
    
    cout << buffer << endl;
  }
}