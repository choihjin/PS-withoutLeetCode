#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// int w(int a, int b, int c) {
//     if(a <= 0 or b <= 0 or c <= 0)
//         return 1;

//     if(a > 20 or b > 20 or c > 20)
//         return w(20, 20, 20);

//     if(a < b and b < c)
//         return w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);

//     return w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
// }

int w[22][22][22] = {1,};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int a = 0; a <= 20; a++)
        for(int b = 0; b <= 20; b++)
            for(int c = 0; c <= 20; c++)
                w[a][b][c] = 1; 
    
    for(int a = 1; a <= 20; a++) {
        for(int b = 1; b <= 20; b++) {
            for(int c = 1; c <= 20; c++) {
                if(a < b && b < c) w[a][b][c] =  w[a][b][c-1] + w[a][b-1][c-1] - w[a][b-1][c];
                else w[a][b][c] = w[a-1][b][c] + w[a-1][b-1][c] + w[a-1][b][c-1] - w[a-1][b-1][c-1];
            }
        }
    }

    while(1) {
        int a, b, c;
        cin >> a >> b >> c;

        if(a == -1 && b == -1 && c == -1) break;

        cout << "w(" << a << ", " << b << ", " << c << ") = ";
        if(a <= 0 || b <= 0 || c <= 0) 
            cout << w[0][0][0] << endl;
        else if(a > 20 or b > 20 or c > 20)
            cout << w[20][20][20] << endl;
        else    
            cout << w[a][b][c] << endl;
    }

    return 0;
}