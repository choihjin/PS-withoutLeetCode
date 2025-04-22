#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

#define EMPTY 0
#define BLOCK 1
#define RAIN 2

int h, w;
int world[502][502] = {0, };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // initialize
    cin >> h >> w;
    for (int i = 0; i < w; i++) {
        int tmp;
        cin >> tmp;
        for (int j = 0; j < tmp; j++) 
            world[j][i] = BLOCK;
    }

    // for(int i = 0; i < h; i++) {
    //     for(int j = 0; j < w; j++) {
    //         cout << world[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // raining 
    int ans = 0;
    for (int i = 0 ; i < h; i++) {
        int l = 0, r = w-1;
        while(l < r) {
            if (world[i][l] == BLOCK && world[i][r] == BLOCK) break;

            if (world[i][l] == EMPTY) l++;
            if (world[i][r] == EMPTY) r--;
        }

        // cout << i << " " << l << " " << r << endl;

        for (int j = l+1; j < r; j++) {
            if (world[i][j] == EMPTY) {
                world[i][j] = RAIN;
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}