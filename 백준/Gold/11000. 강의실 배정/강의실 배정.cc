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
vector<pair<int,int>> arr;
 
void Solve() {
    priority_queue<int, vector<int>, std::greater<>> pq;
    std::sort(arr.begin(), arr.end());

    for(auto& cur : arr){
        pq.push(cur.second);
        if(pq.top() <= cur.first){
            pq.pop();
        }
    }

    cout << pq.size();
}

void Input() {
    cin >> N;
    arr.resize(N);
    for(auto& a : arr){
        cin >> a.first >> a.second;
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
