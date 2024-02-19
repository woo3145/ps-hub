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

int N;
vector<int> arr;
bool visited[100001];

void Solve() {
    int right = 0;
    long long answer = 0;
    for(int i = 0; i < N; ++i){
        while(right < N){
            if(visited[arr[right]]) break;
            visited[arr[right]] = true;
            ++right;
        }
        answer += (right - i);
        visited[arr[i]] = false;
    }
    cout << answer;
}

void Input() {
    cin >> N;
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
