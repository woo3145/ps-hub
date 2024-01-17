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

int N, C;
vector<int> arr;
map<int, int> cache;

void Solve() {
    std::stable_sort(arr.begin(), arr.end(), [](const int& a, const int& b){
        return cache[a] > cache[b];
    });

    for(auto& a : arr){
        for(int i = 0; i < cache[a]; ++i){
            cout << a << ' ';
        }
    }
}

void Input() {
    cin >> N >> C;
    int n;
    for(int i = 0; i < N; ++i){
        cin >> n;

        if(cache.find(n) != cache.end()){
            ++cache[n];
        }else{
            cache[n] = 1;
            arr.push_back(n);
        }
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