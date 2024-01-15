#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::pair;

int N;
vector<int> arr;

void Solve() {
    vector<pair<int, int>> st;

    for(int i = 0; i < arr.size(); ++i){
        while(!st.empty()){
            if(arr[i] < st.back().second) {
                cout << st.back().first << ' ';
                break;
            }
            st.pop_back();
        }
        if(st.empty()){
            cout << 0 << ' ';
        }

        st.push_back({i + 1, arr[i]});
    }
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

