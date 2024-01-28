#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;

int N;
vector<int> arr;
vector<int> tmp;
void Solve() {

    for(int i = 0; i < N; ++i){
        for(int j = i; j < N; ++j){
            tmp.push_back(arr[i] + arr[j]); // a + b
        }
    }

    std::sort(arr.begin(), arr.end());
    std::sort(tmp.begin(), tmp.end());

    for(int i = N - 1; 0 <= i; --i){
        for(int j = i; 0 <= j; --j){
            int sum = arr[i] - arr[j]; // k - c

            if(std::binary_search(tmp.begin(), tmp.end(), sum)){
                cout << arr[i];
                return;
            }
        }
    }
}

void Input() {
    cin >> N;
    arr.resize(N);
    for(auto& a : arr){
        cin >> a;
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
