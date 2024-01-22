#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>

typedef long long ll;

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::queue;
using std::string;
using std::priority_queue;

int N;
priority_queue<ll, vector<ll>, std::greater<>> pq;

void Solve() {
    ll answer = 0;

    while(1 < pq.size()){
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        ll sum = a + b;
        pq.push(sum);
        answer += sum;
    }
    pq.pop();
    cout << answer << '\n';
}

void Input() {
    cin >> N;
    ll t;
    for(int i = 0; i < N; ++i){
        cin >> t;
        pq.push(t);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;

    for(int i = 0; i < T; ++i){    
        Input();
        Solve();
    }
    
    return 0;
}
