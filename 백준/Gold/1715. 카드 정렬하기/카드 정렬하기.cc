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

int N;
priority_queue<int, vector<int>, std::greater<>> pq;

void Solve() {
    int answer = 0;

    while(1 < pq.size()){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum = a + b;
        pq.push(sum);
        answer += sum;
    }

    cout << answer;
}

void Input() {
    cin >> N;
    int t;
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
