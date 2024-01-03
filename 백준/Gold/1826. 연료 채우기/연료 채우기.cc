#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::priority_queue;

int N;
vector<pair<int,int>> stations;
int L, P;

void Input() {
    cin >> N;
    stations.resize(N);

    for(auto& s : stations){
        cin >> s.first >> s.second;
    }

    cin >> L >> P;
}

void Solve() {
    int answer = 0;

    std::sort(stations.begin(), stations.end());

    int curL = P;
    int idx = 0;
    priority_queue<int> pq;

    while(curL < L) {
        while(idx < N && stations[idx].first <= curL){
            pq.push(stations[idx].second);
            ++idx;
        }

        if(pq.empty()) {
            cout << -1;
            return;
        }

        int m = pq.top();
        pq.pop();
        curL += m;
        ++answer;
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();

    return 0;
}
