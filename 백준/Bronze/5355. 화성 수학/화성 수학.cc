#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
  int num;
  vector<string> v;
  string s;
    
  cin >> num;
  getline(cin, s);
  
  for(int i=0; i<num; i++) {
    getline(cin, s);
    v.push_back(s);
  }

  stringstream ss;
  float result;
  char ch;
  for(int i=0; i<v.size(); i++) {
    ss.str(v[i]);
    ss >> result;
    while(ss >> ch) {
      if(ch == '@') {
        result *= 3.0;
      } else if(ch == '%') {
        result += 5.0;
      } else if(ch == '#') {
        result -= 7.0;
      }
    }

    cout << fixed;
    cout.precision(2);
    cout << result << endl;
    ss.clear();
  }
}