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
using std::queue;
using std::string;
using std::priority_queue;

long long N, M;
priority_queue<long long, vector<long long>, std::greater<>> pq;
 
void Solve() {

    for(int i = 0; i < M; ++i){
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        long long sum = a + b;
        pq.push(sum);
        pq.push(sum);
    }

    long long answer = 0;
    while(!pq.empty()){
        answer += pq.top();
        pq.pop();
    }
    cout << answer;
}

void Input() {
    cin >> N >> M;
    long long t;
    for(int i = 0; i < N; ++i){
        cin >> t;
        pq.push(t);
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
