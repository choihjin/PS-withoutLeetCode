#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int num;
    string time;
    stringstream ss;
    int count_y = 0;
    int count_m = 0;
    int cost_y = 0;
    int cost_m = 0;

    cin >> num;
    getline(cin, time);

    getline(cin, time);
    ss.str(time);

    int buffer;
    while(ss >> buffer) {
        count_y = buffer / 30;
        count_m = buffer / 60;

        if(buffer % 30 >= 0) count_y++;
        if(buffer % 60 >= 0) count_m++;

        cost_y += count_y * 10;
        cost_m += count_m * 15;
    }
    
    if(cost_m > cost_y) {
        cout << "Y " << cost_y << endl;
    } else if(cost_y > cost_m) {
        cout << "M " << cost_m << endl;
    } else {
        cout << "Y M " << cost_m << endl;
    }
}