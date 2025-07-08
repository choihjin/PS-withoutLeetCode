#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAX = 2'000'000;
int n;
vector<int> seg(MAX * 4 + 4);

void update(int node, int start, int end, int idx, int val) {
	if (idx < start || end < idx) return;

	if (start == end) {
		seg[node] += val;
		return;
	}

	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int find_kth(int node, int start, int end, int k) {
	if (start == end) return start;
	int left = seg[node * 2];
	int mid = (start + end) / 2;
	if (k <= left) return find_kth(node * 2, start, mid, k);
	else return find_kth(node * 2 + 1, mid + 1, end, k - left);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--) {
		int t, x;
		cin >> t >> x;

		if (t == 1) {
			update(1, 1, MAX, x, 1);
		}
		else {
			int pos = find_kth(1, 1, MAX, x);
			cout << pos << endl;
			update(1, 1, MAX, pos, -1);
		}
	}

	return 0;
}