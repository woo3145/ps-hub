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

int N, K;
int arr[1000001];

void Solve() {
    
    int left = 0;
    int right = 0;
    int sum = 0;
    while(left <= right && right <= 1000000){
        if(K == sum){
            cout << left << ' ' << right;
            return;
        }
        if(sum < K) sum += arr[right++];
        else sum -= arr[left++];
    }

    cout << "0 0";
}

void Input() {
    cin >> N >> K;
    
    int l, r;
    for(int i = 0; i < N; ++i){
        cin >> l >> r;
        for(int j = l; j < r; ++j){
            ++arr[j];
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
