#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int matrix[102][102];
int matrix_tran[102][102];
int used[102][102];
int n, l;

void transpose(int m[102][102], int result[102][102]) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            result[j][i] = m[i][j]; 
        }
    }
}

int solution(int m[102][102]) {
    int cnt = 0;
    for(int i=0; i<n; i++) {
        int possible = 1;
        for(int j=0; j<n-1; j++) {
            if(abs(m[i][j]-m[i][j+1]) > 1) {
                possible = 0;
                break;
            }
            if(m[i][j] > m[i][j+1]) {
                if(used[i][j+1]) {
                    possible = 0;
                    break;
                }
                used[i][j+1] = 1;
                for(int k=1; k<l; k++) {
                    if(m[i][j+1] != m[i][j+k+1] || used[i][j+1+k]) {
                        possible = 0;
                        break;
                    }
                    used[i][j+1+k] = 1;
                }
            }
            else if(m[i][j] < m[i][j+1]) {
                if(used[i][j]) {
                    possible = 0;
                    break;
                }
                used[i][j] = 1;
                for(int k=1; k<l; k++) {
                    if(j-k < 0 || m[i][j] != m[i][j-k] || used[i][j-k]) {
                        possible = 0;
                        break;
                    }
                    used[i][j-k] = 1;
                }
            }
        }
        if(possible) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++) 
            cin >> matrix[i][j];

    int ans = 0;
    ans += solution(matrix);
    transpose(matrix, matrix_tran);
    for(int i=0; i<n; i++) fill(used[i], used[i]+n, 0);
    ans += solution(matrix_tran);

    cout << ans << endl;
}