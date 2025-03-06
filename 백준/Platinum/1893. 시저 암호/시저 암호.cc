#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// 알파벳의 순서 A (3 <= |A| <= 62)
// 원문 P(Plain text) (1 <= |W| <= 50,000)
// 암호문 C(Cypher text) (3 <= |S| <= 500,000)

vector<int> failure(string &s) {
    vector<int> f(s.size());
    int j = 0;
    for(int i=1; i<s.size(); i++) {
        while(j > 0 && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int T;
string A, P, S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    cin.ignore(); // buffer 제거
    while(T--) {
        getline(cin, A);
        getline(cin, P);
        getline(cin, S);

        vector<int> ans;
        // 0 ~ A.size()-1 : Shift 가능한 경우의 수
        for(int shift=0; shift<A.size(); shift++) {
            // PlainText -> CypherText
            string cypher; // temp platintext
            for(auto c : P) {
                int idx = A.find(c);
                cypher += A[(idx + shift) % A.size()];
            }
            
            // KMP
            vector<int> f = failure(cypher);
            int j = 0;
            int cnt = 0;
            for(int i=0; i<S.size(); i++) {
                while(j > 0 && S[i] != cypher[j]) j = f[j-1];
                if(S[i] == cypher[j]) j++;
                if(j == cypher.size()) {
                    cnt++;
                    j = f[j-1];
                }
            }
            
            // CypherText가 단 한번만 포함
            if(cnt == 1) ans.push_back(shift);
        }

        // Print answer
        if(!ans.size()) cout << "no solution" << endl;
        else if(ans.size() == 1) cout << "unique: " << ans[0] << endl;
        else {
            cout << "ambiguous: ";
            for(auto a : ans) cout << a << " ";
            cout << endl;
        }
    }

    return 0;
}