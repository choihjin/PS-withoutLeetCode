#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
long long guitar[12];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string name, play;
        cin >> name >> play;
        for(int j = 0; j < m; j++) {
            if(play[j] == 'Y') {
                guitar[i] |= (1LL << (m - j - 1));
            }
        }
    }

    int min_guitar = INT_MAX;
    int max_song = 0;

    // 전체 기타 조합 탐색 (2^n)
    for(int mask = 1; mask < (1 << n); mask++) {
        long long song_mask = 0;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                song_mask |= guitar[i];
                count++;
            }
        }

        int song_cnt = __builtin_popcountll(song_mask);
        if(song_cnt > max_song) {
            max_song = song_cnt;
            min_guitar = count;
        } else if(song_cnt == max_song) {
            min_guitar = min(min_guitar, count);
        }
    }

    if(max_song == 0) cout << -1 << endl;
    else cout << min_guitar << endl;

    return 0;
}
