#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  char all[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',	'I', 'J', 'K', 'L',	'M', 'N', 'O', 'P', 'Q', 'R',	'S', 'T',	'U', 'V',	'W', 'X',	'Y', 'Z'};

  int n;
  cin >> n;
  
  while(n--) {
    string buffer;
    cin >> buffer;

    string s;
    for(int i=0; i<buffer.size(); i++) {
      bool check = false;
      for(int j=0; j<s.size(); j++) {
        if(s[j] == buffer[i]) {
          check = true;
          break;
        }
      }

      if(!check) s.push_back(buffer[i]);
    }

    int count = 1950 + 'A';
    for(int i=0; i<s.size(); i++) {
      count -= s[i];
    }

    cout << count << "\n";
  }
}