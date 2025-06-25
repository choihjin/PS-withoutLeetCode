#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

int n, q;
ll arr[100'002];
vector<ll> seg;

ll init(int node, int start, int end) {
    if (start == end) return seg[node] = arr[start];
    int mid = (start + end) / 2;
    return seg[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

ll query(int node, int start, int end, int l, int r) {
    if (r < start || l > end) return 0;
    if (l <= start && end <= r) return seg[node];

    int mid = (start + end) / 2;
    return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
}

void update(int node, int start, int end, int idx, ll val) {
    if (idx < start || end < idx) return;

    if (start == end) {
        arr[idx] = val;
        seg[node] = val;
        return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];

    seg.resize(4 * n);
    init(1, 0, n - 1);

    while(q--) {
        int x, y, a;
        ll b;
        cin >> x >> y >> a >> b;

        if (x > y) swap(x, y);
        cout << query(1, 0, n - 1, x - 1, y - 1) << endl;
        update(1, 0, n - 1, a - 1, b);
    }

    return 0;
}