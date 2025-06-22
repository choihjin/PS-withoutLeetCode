#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef long long ll;
int n, m;
vector<ll> arr, seg;

ll build(int node, int start, int end) {
    if (start == end) return seg[node] = start;
    int mid = (start + end) / 2;
    int left = build(node * 2, start, mid);
    int right = build(node * 2 + 1, mid + 1, end);
    return seg[node] = (arr[left] <= arr[right] ? left : right);
}

ll query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return -1;
    if(l <= start && end <= r) return seg[node];
    
    int mid = (start + end) / 2;
    int left = query(node * 2, start, mid, l, r);
    int right = query(node * 2 + 1, mid + 1, end, l, r);

    if (left == -1) return right;
    if (right == -1) return left;
    return (arr[left] <= arr[right] ? left : right);
}

ll update(int node, int start, int end, int idx) {
    if (idx < start || idx > end) return seg[node];
    if (start == end) return seg[node];

    int mid = (start + end) / 2;
    int left = update(node * 2, start, mid, idx);
    int right = update(node * 2 + 1, mid + 1, end, idx);
    return seg[node] = (arr[left] <= arr[right] ? left : right);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    seg.resize(4 * n);
    arr.resize(n + 2);

    for(int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);

    cin >> m;
    while(m--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int i, v;
            cin >> i >> v;
            arr[i] = v;
            update(1, 1, n, i);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }

    return 0;
}