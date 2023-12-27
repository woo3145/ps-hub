#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define lint unsigned long long

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::sqrt;

lint N, M;

void Input() {
    cin >> N >> M;
}

void Solve() {
    int answer = 0;
    
    lint m_root = std::ceil(sqrt(M));
    vector<bool> cache(1000001);

    for(lint p = 2; p <= m_root; ++p){
        lint t = p * p;
        for(lint i = std::ceil((double)N / t) * t; i <= M; i += t){
            if(N <= i){
                cache[i - N] = true;
            }
        }
    }
    for(lint i = N; i <= M; ++i){
        if(!cache[i - N]) ++answer;
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
