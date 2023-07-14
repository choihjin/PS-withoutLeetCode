#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, string> &a, pair<int, string> &b) {
    return a.second < b.second;
}

int main() {
    int n1, n2;
    string dict[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cin >> n1 >> n2;

    int len = n2-n1+1;
    int cnt = n1;
    pair<int, string> res[len];
    for(int i=0; i<len; i++) {
        if(cnt / 10 != 0) 
            res[i].second = dict[cnt/10] + " " + dict[cnt%10];
        else 
            res[i].second = dict[cnt];
        res[i].first = cnt++;
    }

    sort(res, res+len, cmp);

    for(int i=0; i<len; ) {
        cout << res[i].first << " ", i++;
        if(i%10 == 0) cout << "\n";
    }

    return 0;
}