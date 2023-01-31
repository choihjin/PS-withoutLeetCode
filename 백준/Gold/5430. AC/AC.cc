#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        deque<int> D;
        string op;
        int n;
        string s;
        
        cin >> op;
        cin >> n;
        cin >> s;

        // 데이터 전처리
        string buffer;
        for(int i=0; i<s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') buffer += s[i];
            else if(buffer.size()) {
                D.push_back(stoi(buffer));
                buffer = "";
            }
        }

        int rev = 0;
        bool error = false;
        for(char c : op) {
            if(c == 'R') rev = 1 - rev;
            else {
                if(D.empty()) {
                    error = true;
                    break;
                }
                if(!rev) D.pop_front();
                else D.pop_back();
            }
        }

        // 결과 출력
        if(error) cout << "error\n";
        else {
            if(rev) reverse(D.begin(), D.end());
            cout << "[";
            for(int i=0; i<D.size(); i++) {
                if(i == D.size()-1) cout << D[i];
                else cout << D[i] << ",";
            }
            cout << "]\n";
        }
    }
}