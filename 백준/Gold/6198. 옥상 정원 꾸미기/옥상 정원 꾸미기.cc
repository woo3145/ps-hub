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
    long long answer = 0;
    vector<int> st;

    for(int i = 0; i < arr.size(); ++i){
        while(!st.empty()){
            if(arr[i] < st.back()) {
                break;
            }
            st.pop_back();
        }
        answer += st.size();
        st.push_back(arr[i]);
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

