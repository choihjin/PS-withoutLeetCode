#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int h, w, x, y;
int a[302][302];
int b[602][602];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w >> x >> y;
    for(int i = 0; i < h + x; i++) 
        for(int j = 0; j < w + y; j++) 
            cin >> b[i][j];

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(i < x || j < y) a[i][j] = b[i][j];
            else a[i][j] = b[i][j] - a[i-x][j-y];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}