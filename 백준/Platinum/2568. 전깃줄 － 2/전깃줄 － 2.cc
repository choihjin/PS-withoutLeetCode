#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;
pair<int, int> arr[100002];
int prevIdx[100002];     // LIS 경로 추적용
bool inLIS[100002];      // 최종 LIS 포함 여부

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n);  // a 기준 정렬

    vector<int> tail;        // b 값으로 LIS
    vector<int> tailIdx;     // tail[i]에 해당하는 arr의 인덱스 저장

    int path[100002];        // 각 인덱스가 LIS의 어디로 연결됐는지

    for (int i = 0; i < n; i++) {
        int b = arr[i].second;
        auto it = lower_bound(tail.begin(), tail.end(), b);
        int idx = it - tail.begin();

        if (it == tail.end()) {
            tail.push_back(b);
            tailIdx.push_back(i);
        } else {
            *it = b;
            tailIdx[idx] = i;
        }

        if (idx == 0) prevIdx[i] = -1;
        else prevIdx[i] = tailIdx[idx - 1];

        path[i] = idx;
    }

    // LIS 역추적
    int lisLen = tail.size();
    int now = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (path[i] == lisLen - 1) {
            now = i;
            break;
        }
    }
    while (now != -1) {
        inLIS[now] = true;
        now = prevIdx[now];
    }

    cout << n - lisLen << endl;
    for (int i = 0; i < n; i++) {
        if (!inLIS[i]) cout << arr[i].first << endl;
    }

    return 0;
}
