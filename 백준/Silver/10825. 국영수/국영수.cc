#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<tuple<int, int, int, string>> students;
    cin >> n;
    while(n--) {
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;
        students.push_back({-kor, eng, -math, name});
    }
    sort(students.begin(), students.end());
    for(auto s : students) cout << get<3>(s) << "\n";
}
