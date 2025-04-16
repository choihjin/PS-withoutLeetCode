#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;
int green[6][4] = {0, };
int blue[4][6] = {0, };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; 

    int score = 0;
    while(n--) {
        int t, x, y;
        cin >> t >> x >> y;

        // t = 1: 크기가 1×1인 블록을 (x, y)에 놓은 경우
        if (t == 1) {
            // green
            for (int i = 0; i < 6; i++) {
                if (green[i][y]) {
                    green[i-1][y] = 1;
                    break;
                }
                if (i == 5) green[i][y] = 1;
            }
            // blue
            for (int i = 0; i < 6; i++) {
                if (blue[x][i]) {
                    blue[x][i-1] = 1;
                    break;
                }
                if (i == 5) blue[x][i] = 1;
            }
        }

        // t = 2: 크기가 1×2인 블록을 (x, y), (x, y+1)에 놓은 경우
        else if (t == 2) {
            // green
            for (int i = 0; i < 6; i++) {
                if (green[i][y] || green[i][y+1]) {
                    green[i-1][y] = green[i-1][y+1] = 1;
                    break;
                }
                if (i == 5) green[i][y] = green[i][y+1] = 1;
            }
            // blue
            for (int i = 0; i < 6; i++) {
                if (blue[x][i]) {
                    blue[x][i-1] = blue[x][i-2] = 1;
                    break;
                }
                if (i == 5) blue[x][i] = blue[x][i-1] = 1;
            }
        }

        // t = 3: 크기가 2×1인 블록을 (x, y), (x+1, y)에 놓은 경우
        else if (t == 3) {
            // green
            for (int i = 0; i < 6; i++) {
                if (green[i][y]) {
                    green[i-1][y] = green[i-2][y] = 1;
                    break;
                }
                if (i == 5) green[i][y] = green[i-1][y] = 1;
            }
            // blue
            for (int i = 0; i < 6; i++) {
                if (blue[x][i] || blue[x+1][i]) {
                    blue[x][i-1] = blue[x+1][i-1] = 1;
                    break;
                }
                if (i == 5) blue[x][i] = blue[x+1][i] = 1;
            }
        }

        // complete one line
        // green
        for (int i = 5; i >= 0; i--) {
            if(green[i][0] && green[i][1] && green[i][2] && green[i][3]) {
                for (int j = i-1; j >= 0; j--) {
                    memcpy(green[j+1], green[j], sizeof(green[j]));
                }
                memset(green[0], 0, sizeof(green[0]));
                i++;
                score++;
            }
        }
        // blue
        for (int i = 5; i >= 0; i--) {
            if(blue[0][i] && blue[1][i] && blue[2][i] && blue[3][i]) {
                for (int j = 0; j < 4; j++) {
                    memmove(&blue[j][1], &blue[j][0], sizeof(int) * i);
                    blue[j][0] = 0;
                }
                i++;
                score++;
            }
        }

        // check 0, 1
        // green
        for (int i = 1; i >= 0; i--) {
            if(green[i][0] || green[i][1] || green[i][2] || green[i][3]) {
                for (int j = 4; j >= 0; j--) {
                    memcpy(green[j+1], green[j], sizeof(green[j]));
                }
                memset(green[0], 0, sizeof(green[0]));
                i++;
            }
        }
        // blue
        for (int i = 1; i >= 0; i--) {
            if(blue[0][i] || blue[1][i] || blue[2][i] || blue[3][i]) {
                for (int j = 0; j < 4; j++) {
                    memmove(&blue[j][1], &blue[j][0], sizeof(int) * 5);
                    blue[j][0] = 0;
                }
                i++;
            }
        }

        // for debugging
        // cout << t << " " << x << " " << y << endl;
        // for (int i = 0; i < 4; i++) {
        //     for (int j = 0; j < 6; j++) {
        //         cout << blue[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for (int i = 0; i < 6; i++) {
        //     for (int j = 0; j < 4; j++) {
        //         cout << green[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }

    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (green[i][j]) cnt++;
            if (blue[j][i]) cnt++;
        }
    }

    cout << score << endl << cnt << endl;

    return 0;
}