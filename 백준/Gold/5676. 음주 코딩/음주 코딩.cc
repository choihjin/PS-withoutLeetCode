#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, k;
int arr[100'002];
vector<int> seg;

int return_func(int n) {
	if (n > 0) return 1;
	else if (n < 0) return -1;
	else return 0;
}

int init(int node, int start, int end) {
	if (start == end) return seg[node] = return_func(arr[start]);
	int mid = (start + end) / 2;
	return seg[node] = init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end);
}

int query(int node, int start, int end, int l, int r) {
	if (r < start || end < l) return 1;
	if (l <= start && end <= r) return seg[node];

	int mid = (start + end) / 2;
	return query(node * 2, start, mid, l, r) * query(node * 2 + 1, mid + 1, end, l, r);
}

void update(int node, int start, int end, int idx, int val) {
	if (idx < start || end < idx) return;

	if (start == end) {
		arr[idx] = val;
		seg[node] = return_func(val);
		return;
	}

	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	seg[node] = seg[node * 2] * seg[node * 2 + 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> k) {
        for (int i = 0; i < n; i++) cin >> arr[i];

        seg.clear();
        seg.resize(n * 4);
        init(1, 0, n - 1);

        string result;
        while (k--) {
            char cmd;
            cin >> cmd;

            if (cmd == 'C') {
                int i, v;
                cin >> i >> v;
                update(1, 0, n - 1, i - 1, v);
            }
            else if (cmd == 'P') {
                int i, j;
                cin >> i >> j;
                int res = query(1, 0, n - 1, i - 1, j - 1);

                if (res == 1) result += '+';
                else if (res == -1) result += '-';
                else result += '0';
            }
        }
        cout << result << '\n';
    }
    return 0;
}