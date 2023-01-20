#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int buffer, buffer_r;
  string str;
  while(n--) {
    cin >> buffer;
    str = to_string(buffer);
    reverse(str.begin(), str.end());
    buffer_r = stoi(str);

    buffer += buffer_r;
    str = to_string(buffer);
    bool check = true;
    for(int i=0; i<str.size(); i++) {
      if(str[i] != str[str.size()-i-1]) {
        check = false;
        break;
      }
    }
    if(check) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
}