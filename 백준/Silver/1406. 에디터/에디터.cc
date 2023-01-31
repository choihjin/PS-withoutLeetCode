#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, char chr){
    // 1. 새로운 원소 생성
    dat[unused] = chr;

    // 2. 새 원소의 pre값에 삽입할 위치의 주소 대입
    pre[unused] = addr;

    // 3. 새 원소의 nxt값에 삽입할 위치의 nxt값을 대입
    nxt[unused] = nxt[addr]; 

    // 4. 삽입할 위치의 nxt값과 삽입할 위치의 다음 원소의 pre값을 새 원소로 변경
    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    
    // 5. unused 증가
    unused++;
}

void erase(int addr){
    // 1. 이전 위치의 nxt를 삭제할 위치의 nxt로 변경
    nxt[pre[addr]] = nxt[addr];

    // 2. 다음 위치의 pre를 삭제할 위치의 pre로 변경
    if(nxt[ addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur];
    cur = nxt[cur];
  }
  cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    
    string s;
    int cursor = 0;

    cin >> s;
    for(auto c : s) {
        insert(cursor, c);
        cursor++;
    }
    
    int n;
    cin >> n;
    while(n--) {
        char buffer;
        cin >> buffer;
        if(buffer == 'L' && pre[cursor] != -1) cursor = pre[cursor];
        else if(buffer == 'D' && nxt[cursor] != -1) cursor = nxt[cursor];
        else if(buffer == 'B' && pre[cursor] != -1) {
            erase(cursor);
            cursor = pre[cursor];
        }
        else if(buffer == 'P') {
            char dat;
            cin >> dat;
            insert(cursor, dat);
            cursor = nxt[cursor];
        }
    }

    traverse();
}
