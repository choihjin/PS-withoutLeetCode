#include<bits/stdc++.h>
using namespace std;

struct Atom {
	int y, x, d, e;
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int status[4002][4002];
vector<Atom> atom;

int simulate()
{
	int ans = 0;
	while (!atom.empty()) {
		for (int i = 0; i < atom.size(); i++) {
			status[atom[i].y][atom[i].x] = 0;
			int ny = atom[i].y + dy[atom[i].d];
			int nx = atom[i].x + dx[atom[i].d];

			if (nx < 0 || nx > 4000 || ny < 0 || ny > 4000) {
				atom[i].e = 0;
				continue;
			}

			atom[i].x = nx;
			atom[i].y = ny;
			status[ny][nx] += atom[i].e;
		}

		for (int i = 0; i < atom.size(); i++) {
			if (atom[i].e == 0) continue;
			if (status[atom[i].y][atom[i].x] != atom[i].e)
			{
				ans += status[atom[i].y][atom[i].x];
				status[atom[i].y][atom[i].x] = 0;
				atom[i].e = 0;
			}
		}

		vector<Atom> temp;
		temp.assign(atom.begin(), atom.end());
		atom.clear();
		for (int i = 0; i < temp.size(); i++)
			if (temp[i].e)
				atom.push_back(temp[i]);
	}
	return ans;
}

int main(void)
{
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N; cin >> N;
		for (int i = 0; i < N; i++) {
			Atom v;
			cin >> v.x >> v.y >> v.d >> v.e;
			v.x = (v.x + 1000) * 2;
			v.y = (v.y + 1000) * 2;
			atom.push_back(v);
		}
		cout << '#' << tc << ' ' << simulate() << endl;
			
	}
}