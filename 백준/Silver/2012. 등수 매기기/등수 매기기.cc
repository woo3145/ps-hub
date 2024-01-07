#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ll long long

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;


int N;
vector<ll> scores;

void Input() {
    cin >> N;
    scores.resize(N);
    for(auto& s : scores){
        cin >> s;
    }
}

void Solve() {
    std::sort(scores.begin(), scores.end());

    ll sum = 0;

    for(int i = 1; i <= N; ++i){
        sum += std::abs(i - scores[i - 1]);
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
