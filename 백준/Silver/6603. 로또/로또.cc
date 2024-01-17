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
vector<bool> selected;

void Solve() {
    std::sort(arr.begin(), arr.end());

    do{
        for(int i = 0; i < N; ++i){
            if(!selected[i]) continue;
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }while(std::prev_permutation(selected.begin(), selected.end()));
    cout << '\n';
}

void Input() {
    cin >> N;
    if(N == 0) return;

    arr.clear();
    arr.resize(N);
    selected.clear();
    selected.assign(N, false);

    for(auto& a : arr){
        cin >> a;
    }

    for(int i = 0; i < 6; ++i){
        selected[i] = true;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(true){
        Input();
        if(N == 0) break;
        Solve();
    }    
    
    return 0;
}