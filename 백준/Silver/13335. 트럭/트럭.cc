#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, w, L;
int weights[1002];
deque<pair<int, int>> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> L;
    for(int i=0; i<n; i++) 
        cin >> weights[i];

    int sum = 0;
    int time = 0;
    for(int i=0; i<n; i++) {
        int flag = 1;
        while(flag) {
            time++;

            if(!Q.empty()) {
                for(int j=0; j<Q.size(); j++) 
                    Q[j].second++;
                if(Q.front().second >= w) {
                    // cout << time << "초 " << Q.front().first << " out " << endl;
                    sum -= Q.front().first;
                    // cout << "sum : " << sum << endl;
                    Q.pop_front();
                }
            }

            if(sum + weights[i] <= L && Q.size() < w) {
                // cout << time << "초 " << weights[i] << " in " << endl;
                Q.push_back({weights[i], 0});
                sum += Q.back().first;
                // cout << "sum : " << sum << endl;
                flag = 0;
            }

            if(Q.front().second > w) {
                // cout << time << "초 " << Q.front().first << " out " << endl;
                sum -= Q.front().first;
                // cout << "sum : " << sum << endl;
                Q.pop_front();
            }
            
            
        } 
        // 마지막 차량이 다 out 될때까지
        if(i == n-1) {
            while(!Q.empty()) {
                for(int j=0; j<Q.size(); j++) 
                    Q[j].second++;

                if(Q.front().second > w) {
                    // cout << time << "초 " << Q.front().first << " out " << endl;
                    sum -= Q.front().first;
                    // cout << "sum : " << sum << endl;
                    Q.pop_front();
                }
                time++;
            }
        }
    }

    cout << time-1 << endl;

    return 0;
}