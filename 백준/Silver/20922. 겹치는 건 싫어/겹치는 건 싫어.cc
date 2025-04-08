#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, k;
deque<int> sequence;
map<int, int> cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        while (cnt[tmp] >= k) {
            int erase = sequence.front();
            sequence.pop_front();
            cnt[erase]--;
        }
        
        sequence.push_back(tmp);
        cnt[tmp]++;
        ans = max(ans, int(sequence.size()));
    }

    cout << ans << endl;

    return 0;
}