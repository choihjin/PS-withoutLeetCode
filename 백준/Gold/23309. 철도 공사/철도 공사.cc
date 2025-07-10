#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct station {
	int prev;
	int next;
};

int n, m;
station stations[1'000'002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int first_station;
	cin >> first_station;

	int prev_station = first_station;
	for (int i = 1; i < n; i++) {
		int cur_station;
		cin >> cur_station;

		stations[cur_station].prev = prev_station;
		stations[prev_station].next = cur_station;

		prev_station = cur_station;
	}
	int last_station = prev_station;
	stations[first_station].prev = last_station;
	stations[last_station].next = first_station;

	while (m--) {
		string cmd;
		cin >> cmd;

		int cur_station, new_station, removed_station;

		if (cmd == "BN") {
			cin >> cur_station >> new_station;
			int next_station = stations[cur_station].next;

			cout << next_station << endl;

			stations[cur_station].next = new_station;
			stations[new_station].prev = cur_station;
			stations[new_station].next = next_station;
			stations[next_station].prev = new_station;
		}

		else if (cmd == "BP") {
			cin >> cur_station >> new_station;
			int prev_station = stations[cur_station].prev;

			cout << prev_station << endl;

			stations[prev_station].next = new_station;
			stations[new_station].prev = prev_station;
			stations[new_station].next = cur_station;
			stations[cur_station].prev = new_station;
		}
		
		else if (cmd == "CN") {
			cin >> cur_station;
			removed_station = stations[cur_station].next;

			cout << removed_station << endl;

			int next_station = stations[removed_station].next;
			stations[cur_station].next = next_station;
			if (next_station != 0)
				stations[next_station].prev = cur_station;
		}

		else if (cmd == "CP") {
			cin >> cur_station;
			removed_station = stations[cur_station].prev;

			cout << removed_station << endl;

			int prev_prev_station = stations[removed_station].prev;
			stations[cur_station].prev = prev_prev_station;
			if (prev_prev_station != 0)
				stations[prev_prev_station].next = cur_station;
		}
	}

	return 0;
}
