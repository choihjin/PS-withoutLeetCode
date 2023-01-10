#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  int num;
  string a;
  string b;
  stringstream ss;
  int buffer;
  vector<int> num1;
  vector<int> num2;
  
  cin >> num;
  getline(cin, a);

  getline(cin, a);
  ss.str(a);
  while(ss >> buffer) num1.push_back(buffer);
  ss.clear();
  
  getline(cin, b);
  ss.str(b);
  while(ss >> buffer) num2.push_back(buffer);

  int temp;
  for(int i=0; i<num1.size(); i++) {
    for(int j=0; j<num1.size()-1-i; j++) {
      if(num1[j] > num1[j+1]) {
        temp = num1[j];
        num1[j] = num1[j+1];
        num1[j+1] = temp;
      }
    }
  }

  for(int i=0; i<num2.size(); i++) {
    for(int j=0; j<num2.size()-1-i; j++) {
      if(num2[j] < num2[j+1]) {
        temp = num2[j];
        num2[j] = num2[j+1];
        num2[j+1] = temp;
      }
    }
  }

  int result = 0;
  for(int i=0; i<num1.size(); i++) {
    result += num1[i] * num2[i];
  }

  cout << result << endl;
  return 0;
}