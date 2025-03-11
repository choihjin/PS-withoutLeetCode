#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

unordered_set<char> default_set = {'a', 'n', 't', 'i', 'c'};
unordered_set<char> study_set[52];
unordered_set<char> search_set;
vector<char> search_vec;
int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;  
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for(char c : tmp) {
            if(default_set.find(c) == default_set.end()) {
                study_set[i].insert(c);
                if(search_set.find(c) == search_set.end()) {
                    search_set.insert(c);
                    search_vec.push_back(c);  // 안전한 인덱싱을 위해 vector 사용
                }
            }
        }
    }

    if(k < 5) {
        cout << 0 << endl;
        return 0;
    }

    int total_chars = search_vec.size();
    int select_count = k - 5;

    if(select_count > total_chars) {
        select_count = total_chars;  // 선택할 글자가 부족할 경우 최대한 선택
    }

    // 선택할 글자가 없는 경우 바로 종료
    if (select_count < 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<bool> v(total_chars - select_count, false);
    v.insert(v.end(), select_count, true);

    int ans = 0;
    do {
        unordered_set<char> learned;
        for (int i = 0; i < total_chars; i++) 
            if(v[i]) learned.insert(search_vec[i]);
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            bool read = true;
            for(char c : study_set[i]) {
                if(learned.find(c) == learned.end()) {
                    read = false;
                    break;
                }
            }
            if(read) cnt++;
        }
        ans = max(ans, cnt);
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;

    return 0;
}
