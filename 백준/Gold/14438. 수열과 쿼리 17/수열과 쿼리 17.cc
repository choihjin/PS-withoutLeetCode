#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m;
int arr[100'002];
vector<int> seg;

int init(int node, int start, int end) {
    if (start == end) return seg[node] = arr[start];
    int mid = (start + end) / 2;
    return seg[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return INT_MAX;
    if (l <= start && end <= r) return seg[node];

    int mid = (start + end) / 2;
    return min(query(node * 2, start, mid, l, r), query(node * 2 + 1, mid + 1, end, l, r));
}   

void update(int node, int start, int end, int idx, int val) {
    if (idx < start || idx > end) return;

    if (start == end) {
        arr[idx] = val;
        seg[node] = val;
        return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
    seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    seg.resize(4 * n);
    init(1, 0, n - 1);
    
    cin >> m;
    while(m--) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int i, v;
            cin >> i >> v;
            update(1, 0, n - 1, i - 1, v);
        }
        else {
            int i, j;
            cin >> i >> j;
            cout << query(1, 0, n - 1, i - 1, j - 1) << endl;
        }
    }

    return 0;
}