#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::ceil;

int N, M, K;

void Input() {
    cin >> N >> M >> K;
}

void Solve() {
    int cnt = 0;

    while(1 < N && M){
        N -= 2;
        M -= 1;
        ++cnt;
    }

    float rest = K - (N + M);
    if(0 < rest){
        cout << cnt - ceil(rest / 3);
        return; 
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();
    
    return 0;
}
