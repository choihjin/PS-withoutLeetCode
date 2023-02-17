#include <bits/stdc++.h>
using namespace std;

#define cnt first
#define num second

int n, c;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.cnt > b.cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> c;

  vector<pair<int, int>> arr;
  for (int i = 0; i < n; i++) {
    int buffer;
    cin >> buffer;
    bool chk = false;
    for (auto &a : arr) {
      if (a.num == buffer) {
        chk = true;
        a.cnt++;
        break;
      }
    }
    if (!chk) arr.push_back({1, buffer});
  }
  stable_sort(arr.begin(), arr.end(), cmp);

  for (auto b : arr)
    while (b.cnt--)
      cout << b.num << ' ';
}