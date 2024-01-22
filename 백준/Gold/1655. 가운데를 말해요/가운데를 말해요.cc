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
vector<int> arr;
priority_queue<int> max_pq;
priority_queue<int, vector<int>, std::greater<>> min_pq;

void Solve() {
    int answer = 0;

    for(int i = 0; i < N; ++i){
        if(max_pq.size() == min_pq.size()) max_pq.push(arr[i]);
        else min_pq.push(arr[i]);

        if(!max_pq.empty() && !min_pq.empty() && min_pq.top() < max_pq.top()){
            int a = max_pq.top();
            int b = min_pq.top();
            min_pq.pop(); max_pq.pop();

            min_pq.push(a); max_pq.push(b);
        }

        cout << max_pq.top() << '\n';
    }
}

void Input() {
    cin >> N;
    arr.resize(N);
    for(auto& a : arr){
        cin >> a;
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
