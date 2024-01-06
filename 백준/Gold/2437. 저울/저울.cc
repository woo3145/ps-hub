#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::ios;
using std::cout;
using std::cin;
using std::vector;

int N;
vector<int> nums;

void Input() {
    cin >> N;
    nums.resize(N);
    for(auto& n : nums){
        cin >> n;
    }    
}

void Solve() {
    std::sort(nums.begin(), nums.end());

    int answer = 1;
    for(auto& a : nums){
        if(answer < a){
            break;
        }
        answer += a;
    }
    cout << answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve(); 
    
    return 0;
}
