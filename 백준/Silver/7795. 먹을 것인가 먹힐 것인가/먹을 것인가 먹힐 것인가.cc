#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::queue;
using std::string;
using std::map;
using std::set;



int N, M;
vector<int> aArr, bArr;

void Solve() {
    std::sort(aArr.begin(), aArr.end());
    std::sort(bArr.begin(), bArr.end());
    int answer = 0;
    int cur = 0;
    for(int i = 0; i < N; ++i){
        while(cur < M && bArr[cur] < aArr[i]) {
            ++cur;
        }
        answer += cur;
    }

    cout << answer << '\n';
}

void Input() {
    cin >> N >> M;
    aArr.clear();
    bArr.clear();
    
    aArr.resize(N);
    for(auto& a : aArr){
        cin >> a;
    }
    bArr.resize(M);
    for(auto& a : bArr){
        cin >> a;
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