#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define N 0
#define S 1
#define num first
#define dir second

deque<int> wheel[4];
vector<pair<int, int>> seq;
int k;

int main() {
    for(int i=0; i<4; i++) {
        string str;
        cin >> str;
        for(int j=0; j<8; j++) {
            wheel[i].push_back(str[j]-'0');
        }
    }
    cin >> k;
    for(int i=0; i<k; i++) {
        int n, d;
        cin >> n >> d;
        seq.push_back({n, d});
    }
    
    // solution
    for(int i=0; i<k; i++) {
        int n = seq[i].num;
        int d = seq[i].dir;
        int dirs[4] ={0,}; // save directions
        dirs[n-1] = d;

        // left check
        int idx = n-1;
        while(idx-1 >= 0) {
            if(wheel[idx][6] == wheel[idx-1][2])
                break;
            dirs[idx-1] = dirs[idx] * -1;
            idx--;
        }

        // right check
        idx = n-1;
        while(idx+1 < 4) {
            if(wheel[idx][2] == wheel[idx+1][6])
                break;
            dirs[idx+1] = dirs[idx] * -1;
            idx++;
        }

        // rotate
        for(int i=0; i<4; i++) {
            if(!dirs[i]) continue;
            else if(dirs[i] == 1) {
                int tmp = wheel[i][7]; 
                wheel[i].pop_back();
                wheel[i].push_front(tmp);
            }
            else {
                int tmp = wheel[i][0]; 
                wheel[i].pop_front();
                wheel[i].push_back(tmp);
            }
        }
    }

    int ans = 0, tmp = 1;
    for(int i=0; i<4; i++) {
        if(wheel[i][0] == S) ans += tmp;
        tmp *= 2;
    }

    cout << ans << endl;
}