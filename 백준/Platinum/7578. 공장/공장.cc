#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MAX 500001

int n;
int a[MAX];
int tree[MAX * 4];

void update(int node, int start, int end, int idx) {
    if (idx < start || idx > end) return;
    tree[node]++;
    if (start == end) return;

    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx);
    update(node * 2 + 1, mid + 1, end, idx);
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    return query(node * 2, start, mid, l, r) +
           query(node * 2 + 1, mid + 1, end, l, r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    map<int, int> b_index;

    // A열 입력
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    // B열 → 위치 기록
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b_index[x] = i;
    }

    // A열의 식별번호를 B열 위치 인덱스로 변환
    for (int i = 0; i < n; i++) {
        a[i] = b_index[A[i]];
    }

    // 역순쌍 개수 세기
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += query(1, 0, n - 1, a[i] + 1, n - 1);  // 오른쪽에 나보다 작은 수 개수
        update(1, 0, n - 1, a[i]);  // 현재 값 추가
    }

    cout << ans << "\n";
    return 0;
}