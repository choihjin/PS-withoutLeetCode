#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int pre[MX], nxt[MX];
int len = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    vector<int> v;

    cin >> n >> k;
    // 시작과 끝을 이어 circular linked list 생성
    for(int i=1; i<=n; i++) {
        if(i != 1) pre[i] = i-1;
        else pre[i] = n;

        if(i != n) nxt[i] = i+1;
        else nxt[i] = 1;

        len++;
    }

    int cursor = 1;
    while(len != 0) {
        // k번째로 커서 이동
        for(int i=0; i<k-1; i++) {
            cursor = nxt[cursor];
        }

        // 저장 및 삭제
        v.push_back(cursor);
        pre[nxt[cursor]] = pre[cursor];
        nxt[pre[cursor]] = nxt[cursor];
        // 커서 이동 및 길이 조정
        cursor = nxt[cursor];
        len--;
    }

    // 요세푸스 순열 출력
    cout << "<";
    for(int i=0; i<v.size(); i++) {
        if(i == v.size()-1) cout << v[i];
        else cout << v[i] << ", ";
    }
    cout << ">\n";
}