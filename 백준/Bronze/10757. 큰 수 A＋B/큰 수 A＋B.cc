#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    // 01. 계산을 편리하게 하기 위해 A에 긴 문자열 배치
    if(b.size() > a.size()) {
        swap(a, b);
    }

    // 02. 자리수가 다르면 0을 채워넣기
    if(b.size() != a.size()) {
        string temp = "";
        for(int i=0; i<(a.size()-b.size()); i++) {
            temp += "0";
        }
        b = temp + b;
    }

    // 03. 뒷자리부터 계산해서 push
    vector<int> ans;
    int carry = 0;
    int temp;
    for(int i=a.size()-1; i>=0; i--) {
        temp = (a[i]-'0') + (b[i]-'0');
        if(carry == 1) {
            temp++;
            carry = 0;
        }
        if(temp > 9) {
            carry = 1;
            temp -= 10;
        }
        ans.push_back(temp);
    }
    if(carry == 1) ans.push_back(1);

    // 04. 반대로 출력
    for(int i=ans.size()-1; i>=0; i--) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}