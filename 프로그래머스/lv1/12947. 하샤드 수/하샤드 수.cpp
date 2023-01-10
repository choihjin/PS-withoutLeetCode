#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    string s = to_string(x);
    
    int total = 0;
    for(int i=0; i<s.size(); i++) {
        total += s[i]-48;
    }
    
    if(x % total == 0) return true; 
    else return false;
}