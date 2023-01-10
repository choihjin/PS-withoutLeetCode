#include <iostream>
#include <vector>

using namespace std;

int main() {
  string str;
  vector<char> ch;
  vector<int> count;
  cin >> str;

  for(int i=0; i<str.size(); i++) {
    str[i] = toupper(str[i]);
    bool check = false;
    for(int j=0; j<ch.size(); j++) {
      if(ch[j] == str[i]) {
        check = true;
        count[j]++;
        break;
      }
    }
    if(!check) {
      ch.push_back(str[i]);
      count.push_back(1);
    }
  }

  int max = 0;
  for(int i=0; i<count.size(); i++) {
    if(max < count[i]) {
      max = count[i];
    }
  }

  vector<char> ans;
  for(int i=0; i<count.size(); i++) {
    if(max == count[i]) {
      ans.push_back(ch[i]);
    }
  }

  if(ans.size() > 1) {
    cout << "?" << endl;
  } else {
    cout << ans[0] << endl;
  }
}