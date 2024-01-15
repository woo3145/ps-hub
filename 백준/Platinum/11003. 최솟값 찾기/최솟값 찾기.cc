#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::pair;
using std::deque;

typedef long long ll;

int N, L;
vector<int> arr;

void Solve() {
    deque<pair<int,int>> deq;

    for(int i = 0; i < N; ++i){
        // 범위를 벗어나면 pop_front
        while(!deq.empty() && deq.front().second <= i - L) deq.pop_front();
        // deq.back 보다 현재값 더 작으면 pop_back
        while(!deq.empty() && arr[i] <= deq.back().first) deq.pop_back();

        deq.push_back({arr[i], i});
        cout << deq.front().first << ' ';
    }
}

void Input() {
    cin >> N >> L;
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

