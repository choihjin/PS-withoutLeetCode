#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef long long ll;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<ll> h(n + 1); // 높이 저장 (n+1은 Sentinel)
    for (int i = 0; i < n; i++) 
        cin >> h[i];
    
    h[n] = 0; // Sentinel 추가 (남은 스택 정리 목적)

    stack<int> s; // 인덱스를 저장하는 스택
    ll ans = 0; // 최대 직사각형 넓이

    for (int i = 0; i <= n; i++) {
        // 현재 높이가 스택의 top보다 낮으면 pop
        while (!s.empty() && h[s.top()] > h[i]) {
            ll height = h[s.top()]; s.pop();
            // 스택이 비었으면 왼쪽 끝은 0, 아니면 이전 인덱스 다음 칸
            ll width = i - (s.empty() ? 0 : s.top() + 1);
            ans = max(ans, height * width); // 넓이 계산 후 최대값 갱신
        }
        s.push(i); // 현재 인덱스 스택에 삽입
    }

    cout << ans << endl; // 결과 출력

    return 0;
}