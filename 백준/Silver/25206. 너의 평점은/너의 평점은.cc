#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

double check_grade(string str) {
    if(str == "A+")
        return 4.5;
    else if(str == "A0")
        return 4.0;
    else if(str == "B+")
        return 3.5;
    else if(str == "B0")
        return 3.0;
    else if(str == "C+")
        return 2.5;
    else if(str == "C0")
        return 2.0;
    else if(str == "D+")
        return 1.5;
    else if(str == "D0")
        return 1.0;
    else if(str == "F")
        return 0;
    else if(str == "P")
        return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    double num;
    string grade;

    double sum = 0;
    double sum_num = 0;
    for(int i=0; i<20; i++) {
        cin >> str >> num >> grade;
        if(check_grade(grade) != -1) {
            sum += num * check_grade(grade);
            sum_num += num;
        }
        // cout << str << " " << num << " " << grade << endl;
    }

    cout << sum / sum_num << endl;

    return 0;
}