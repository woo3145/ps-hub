#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;

int N;
vector<pair<ll, ll>> info;

ll sum = 0;

void Input() {
    cin >> N;
    info.resize(N);

    for(auto& i : info){
        cin >> i.first >> i.second;
        sum += i.second;
    }
}

void Solve() {
    std::sort(info.begin(), info.end());
    
    ll half = (sum + 1) / 2;
    ll cur = 0;
    for(int i = 0; i < N; ++i){
        cur += info[i].second;

        if(half <= cur){
            cout << info[i].first;
            return;
        }
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
