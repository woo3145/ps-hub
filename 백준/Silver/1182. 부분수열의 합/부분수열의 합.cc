#include <iostream>
#include <vector>

using std::ios;
using std::cout;
using std::cin;
using std::vector;

int N, S;
vector<int> arr;
int sum = 0;
int answer = 0;

void backTracking(int idx, int sum){
    if(idx == N){
        if(sum == S) ++answer;
        return;
    }

    backTracking(idx + 1, sum);
    backTracking(idx + 1, sum + arr[idx]);
}

void Solve() {
    backTracking(0, 0);
    if(S == 0) answer -= 1;
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