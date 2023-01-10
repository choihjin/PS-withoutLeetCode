#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int t = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] >=65 && s[i] <= 67) {
            t += 3;
        } else if(s[i] >= 68 && s[i] <= 70) {
            t += 4;
        } else if(s[i] >= 71 && s[i] <= 73) {
            t += 5;
        } else if(s[i] >= 74 && s[i] <= 76) {
            t += 6;
        } else if(s[i] >= 77 && s[i] <= 79) {
            t += 7;
        } else if(s[i] >= 80 && s[i] <= 83) {
            t += 8;
        } else if(s[i] >= 84 && s[i] <= 86) {
            t += 9;
        } else if(s[i] >= 87 && s[i] <= 90) {
            t += 10;
        }
    }
    cout << t << endl;
}