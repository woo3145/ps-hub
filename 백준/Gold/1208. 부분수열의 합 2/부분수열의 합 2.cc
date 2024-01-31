#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::map;
using std::string;
using std::queue;

struct Pos {
    int y, x;
};

int N, S;
vector<int> arr;
map<int, int> cache;
long long answer = 0;

void checkLeft(int idx, int sum){
    if(idx == N / 2){
        cache[sum] += 1;
        return;
    }

    checkLeft(idx + 1, sum + arr[idx]);
    checkLeft(idx + 1, sum);
}

void checkRight(int idx, int sum){
    if(idx == N){
        answer += cache[S - sum];
        return;
    }
    checkRight(idx + 1, sum + arr[idx]);
    checkRight(idx + 1, sum);
}

void Solve() {
    checkLeft(0, 0);
    checkRight(N / 2, 0);

    if(S == 0) --answer;
    cout << answer;
}

void Input() {
    cin >> N >> S;
    arr.resize(N);

    for(auto& n : arr){
        cin >> n;
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
