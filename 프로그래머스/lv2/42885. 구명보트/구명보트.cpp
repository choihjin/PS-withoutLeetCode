#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int begin = 0;
    int end = people.size() - 1;
    sort(people.begin(), people.end());

    while (begin <= end) {
        if (people[begin] + people[end] <= limit) begin++;
        end--;
        answer++;
    }
    return answer;
}