#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int month[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string day[] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
    
    int sum = b-1;
    
    for(int i=0; i<a-1; i++){
        sum += month[i];
    }

    return day[sum%7];
}
