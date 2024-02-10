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

int K, L;
map<string, int> cache;

void Solve() {
    vector<string> arr;
    arr.reserve(L);
    string s;
    for(int i = 0; i < L; ++i){
        cin >> s;

        if(cache[s]) ++cache[s];
        else cache[s] = 1;
        arr.push_back(s);
    }
    int idx = 0;
    while(K && idx < L){
        --cache[arr[idx]];
        if(cache[arr[idx]] == 0){
            cout << arr[idx] << '\n';
            --K;
        }
        ++idx;
    }
    
}

void Input() {
    cin >> K >> L;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();
    
    return 0;
}
