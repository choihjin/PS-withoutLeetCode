#include <bits/stdc++.h>
using namespace std;

int raptop[42][42];
int sticker[12][12];
int n, m, k;
int r, c;

bool pastable(int x, int y) { // raptop의 시작점을 받아서 스티커를 붙일 수 있는지 판단
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      if (sticker[i][j] == 1 && raptop[x + i][y + j] == 1)
        return false;

  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      if (sticker[i][j] == 1)
        raptop[x+i][y+j] = 1;
  return true;
}

void rotate() {
  int temp[12][12];

  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      temp[i][j] = sticker[i][j];

  for (int i = 0; i < c; i++)
    for (int j = 0; j < r; j++)
      sticker[i][j] = temp[r-j-1][i];

  swap(r, c);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  while (k--) {
    cin >> r >> c;
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        cin >> sticker[i][j];
    
    for (int rot=0; rot<4; rot++) {
      bool is_paste = false; // 스티커를 붙였으면 종료
      for (int x=0; x<=n-r; x++) {
        if (is_paste) break;
        for (int y=0; y<=m-c; y++) {
          if(pastable(x, y)) {
            is_paste = true;
            break;
          }
        }
      }
      if(is_paste) break;
      rotate();
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cnt += raptop[i][j];
  cout << cnt << "\n";
}