#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef long long ll;
int n;
int m; // 변경 횟수
int k; // 구간 합 횟수
ll arr[1000002];
vector<ll> tree;

ll init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

ll query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) +
        query(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, ll val) {
    if (idx < start || idx > end) return;

    if (start == end) {
        arr[idx] = val;
        tree[node] = val;
        return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];

    tree.resize(n * 4);
    init(1, 0, n - 1);

    for(int i = 0; i < m + k; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        if(a == 1) {
            update(1, 0, n - 1, b - 1, c);
        }
        else if(a == 2) {
            cout << query(1, 0, n - 1, b - 1, c - 1) << endl;
        }
    }

    return 0;
}
