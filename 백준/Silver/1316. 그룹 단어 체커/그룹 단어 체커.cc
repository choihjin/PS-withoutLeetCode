#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int count = 0;
  for(int i=0; i<n; i++) {
    string buffer;
    cin >> buffer;

    string s = "";
    for(int j=0; j<buffer.size(); j++) {
      if(buffer[j] != buffer[j-1]) s += buffer[j];
    }
    buffer = s;
    
    bool check = true;
    for(int j=0; j<buffer.size(); j++) {
      for(int h=0; h<j; h++) {     
        if(buffer[j] == buffer[h]) {
          check = false;
          break;
        }
      }  
      if(!check) break;
    }
    if(check) count++;
  }

  cout << count << endl;
}