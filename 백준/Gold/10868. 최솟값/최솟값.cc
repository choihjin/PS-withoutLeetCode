#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m;
int arr[100'102];
vector<int> seg;

int init(int node, int start, int end) {
    if (start == end) return seg[node] = arr[start];
    int mid = (start + end) / 2;
    return seg[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || l > end) return INT_MAX;
    if (l <= start && end <= r) return seg[node];
    
    int mid = (start + end) / 2;
    return min(query(node * 2, start, mid, l, r), 
        query(node * 2 + 1, mid + 1, end, l , r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];

    seg.resize(4 * n);
    init(1, 0, n - 1);

    while(m--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 0, n - 1, l - 1, r - 1) << endl;
    }

    return 0;
}