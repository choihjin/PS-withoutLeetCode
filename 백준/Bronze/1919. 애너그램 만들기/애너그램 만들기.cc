#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  cin >> a >> b;

  int arr[26] = {};
  int arr2[26] = {};
  for(auto i : a) arr[i-'a']++;
  for(auto i : b) arr2[i-'a']++;

  //배열 데이터가 다르면 차이값을 카운트
  int count = 0;
  for(int i=0; i<26; i++) {
    if(arr[i] != arr2[i]) {
      if(arr[i] > arr2[i]) count += arr[i]-arr2[i];
      else count += arr2[i]-arr[i];
    }
  }
  cout << count << "\n";
}