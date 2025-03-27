#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> tail;            // LIS 길이 추적
    vector<int> tail_idx;        // tail의 실제 인덱스
    vector<int> prev(n, -1);     // 각 원소의 이전 위치 추적

    for(int i = 0; i < n; i++) {
        int x = arr[i];
        auto it = lower_bound(tail.begin(), tail.end(), x);
        int pos = it - tail.begin();

        if(it == tail.end()) {
            tail.push_back(x);
            tail_idx.push_back(i);
        } else {
            *it = x;
            tail_idx[pos] = i;
        }

        if(pos != 0) prev[i] = tail_idx[pos - 1]; // 이전 원소 인덱스 저장
    }

    // LIS 길이
    cout << tail.size() << "\n";

    // LIS 복원
    vector<int> lis;
    int idx = tail_idx.back();  // 마지막 원소부터 추적 시작
    while(idx != -1) {
        lis.push_back(arr[idx]);
        idx = prev[idx];
    }

    reverse(lis.begin(), lis.end());
    for(int x : lis) cout << x << " ";
    cout << "\n";

    return 0;
}
