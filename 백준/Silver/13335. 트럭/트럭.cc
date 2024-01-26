#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::deque;
using std::string;
using std::deque;

int N, W, L;
vector<int> trucks;

void Solve() {
    deque<pair<int, int>> bridge;
    int answer = 0;
    int sum = 0;

    int curIdx = 0;
    while(curIdx < N){
        for(int i = 0; i < bridge.size(); ++i){
            bridge[i].second -= 1;
        }

        if(!bridge.empty() && bridge.front().second <= 0){
            sum -= trucks[bridge.front().first];
            bridge.pop_front();
        }

        if(sum + trucks[curIdx] <= L){
            bridge.push_back({curIdx, W});
            sum += trucks[curIdx];
            ++curIdx;
        }
        
        ++answer;
    }

    if(!bridge.empty()){
        answer += bridge.back().second;
    }

    cout << answer;
}

void Input() {
    cin >> N >> W >> L;
    trucks.resize(N);
    for(auto& n : trucks){
        cin >> n;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();
    
    return 0;
}
