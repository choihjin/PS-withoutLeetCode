#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  int count = 0;
  cin >> s;
  
  for(int i=0; i<s.size(); i++) {
    if((s[i] == 'c' && s[i+1] == '=') || (s[i] == 'c' && s[i+1] == '-')) {
      count++;
      i++;
    } else if((s[i] == 'd' && s[i+1] == '-') || (s[i] == 'd' && s[i+1] == 'z' && s[i+2] == '='))    {
      if(s[i+1] == '-') {
        count++;
        i++;
      } else {
        count++;
        i += 2;
      }
    } else if((s[i] == 'l' && s[i+1] == 'j') || (s[i] == 'n' && s[i+1] == 'j')) {
      count++;
      i++;
    } else if((s[i] == 's' && s[i+1] == '=') || (s[i] == 'z' && s[i+1] == '=')) {
      count++;
      i++;
    } else count++;
  }

  cout << count << endl;
}