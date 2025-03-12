#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define TOP 0
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4
#define BOTTOM 5

int board[22][22];
int dice[6];
int n, m, x, y, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> y >> x >> k;
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) 
            cin >> board[j][i];
            
    int cmd;
    while(k--) {
        cin >> cmd;

        int east, west, south, north, top, bottom;
        east = dice[EAST];
        west = dice[WEST];
        south = dice[SOUTH];
        north = dice[NORTH];
        top = dice[TOP];
        bottom = dice[BOTTOM];

        if(cmd == EAST) {
            if(x + 1 >= m) continue;
            x++;
            dice[EAST] = top;
            dice[WEST] = bottom;
            dice[TOP] = west;
            dice[BOTTOM] = east;
        }
        else if(cmd == WEST) {
            if(x - 1 < 0) continue;
            x--;
            dice[EAST] = bottom;
            dice[WEST] = top;
            dice[TOP] = east;
            dice[BOTTOM] = west;
        }
        else if(cmd == SOUTH) {
            if(y + 1 >= n) continue;
            y++;
            dice[NORTH] = top;
            dice[TOP] = south;
            dice[SOUTH] = bottom;
            dice[BOTTOM] = north;
        }
        else {
            if(y - 1 < 0) continue;
            y--;
            dice[NORTH] = bottom;
            dice[TOP] = north;
            dice[SOUTH] = top;
            dice[BOTTOM] = south;
        }

        if(board[x][y] == 0) board[x][y] = dice[BOTTOM];
        else {
            dice[BOTTOM] = board[x][y];
            board[x][y] = 0;
        }

        cout << dice[TOP] << endl;
    }

    return 0;
}