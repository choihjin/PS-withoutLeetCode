#include <iostream>
#include <ctime>

using namespace std;

int main() {
    time_t t = time(nullptr);
    tm *now = localtime(&t);
    cout << (now->tm_year + 1900) << '-';

    cout.width(2);
    cout.fill('0');
    cout << (now->tm_mon + 1) << '-';

    cout.width(2);
    cout.fill('0');
    cout << now->tm_mday;
    return 0;
}