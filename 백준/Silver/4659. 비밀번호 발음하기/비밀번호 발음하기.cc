#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    bool check;
    while(1) {
        check = false;
        cin >> str;
        if(str == "end") break;

        // check case 1
        if(str.find('a') == -1 && str.find('e') == -1 && str.find('i') == -1 
            && str.find('o') == -1  && str.find('u') == -1)
            check = true;
        
        // chech case 2
        if(!check) {
            int vowel = 0, cons = 0;
            for(int i=0; i<str.size(); i++) {
                if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
                    vowel++;
                    if(cons > 0) cons = 0;
                }
                else {
                    cons++;
                    if(vowel > 0) vowel = 0;
                }

                if(vowel >= 3 || cons >= 3) {
                    check = true;
                    break;
                }
            }
        }

        // chech case 3
        if(!check) {
            char prev = str[0];
            for(int i=1; i<str.size(); i++) {
                if(prev == str[i] && prev != 'e' && prev != 'o') {
                    check = true;
                    break;
                }
                prev = str[i];
            }
        }

        if(check) {
            cout << "<" << str << "> is not acceptable.\n";
        }
        else {
            cout << "<" << str << "> is acceptable.\n";
        }
    }
}