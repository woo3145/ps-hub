#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::queue;
using std::string;

int N, M;
vector<int> arr;
vector<int> cnt;

void Solve() {
    std::sort(arr.begin(), arr.end());
    
    do{ 
        for(int i = 0; i < N; ++i){
            if(!cnt[i]) continue;
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }while(std::prev_permutation(cnt.begin(), cnt.end()));
}

void Input() {
    cin >> N >> M;
    
    arr.resize(N);
    cnt.resize(N, 0);

    for(auto& a : arr){
        cin >> a;
    }

    for(int i = 0; i < M; ++i){
        cnt[i] = 1;
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