#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::priority_queue;

int N;
vector<pair<int, int>> info; 

void Input() {
    cin >> N;
    info.resize(N);
    
    for(auto& i : info) {
        cin >> i.first;
        cin >> i.second;
    }
}

// 6 1
// 3 1
// 9 2    *
// 4 2
// 2 4
// 2 5
// 1 6
// 1 7

// 마감일 / 보상

void Solve() {
    priority_queue<int, vector<int>, std::greater<>> answer;

    std::sort(info.begin(), info.end(), [](const auto& a, const auto& b) {
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    });
    
    int day = 0;
    for(auto& i : info) {
        // 문제를 풀면 day + 1, 컵라면 받기
        if(day < i.first) {
            answer.push(i.second);
            ++day;
        }else{
        // 데드라인이 겹치면 현재 보상이 여태받은 보상중 가장 작은거랑 비교하여 교체
            if(answer.top() < i.second) {
                answer.pop();
                answer.push(i.second);
            }
        }
    }

    int sum = 0;
    while(!answer.empty()){
        sum += answer.top();
        answer.pop();
    }
    cout << sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();
    
    return 0;
}
