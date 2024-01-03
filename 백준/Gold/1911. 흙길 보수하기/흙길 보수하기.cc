#include <iostream>
#include <vector>
#include <algorithm>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;

int N, L;
vector<pair<int, int>> holes;

void Input() {
    cin >> N >> L;
    holes.resize(N);

    for(auto& h : holes){
        cin >> h.first >> h.second;
    }
}

void Solve() {
    std::sort(holes.begin(), holes.end());
    int answer = 0;

    int cur = 0;
    for(const auto& h : holes){
        if(cur < h.first) cur = h.first;

        int tmp = (h.second - cur + L - 1) / L;

        answer += tmp;
        cur += L * tmp;
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
