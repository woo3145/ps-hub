#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::next_permutation;

int N;
vector<int> nums;
vector<int> operators;


void Input() {
    cin >> N;
    nums.resize(N);
    
    for(auto& n : nums){
        cin >> n;
    }
    int c;
    for(int i = 0; i < 4; ++i){
        cin >> c;
        for(int j = 0; j < c; ++j){
            operators.push_back(i);
        }
    }
}

void Solve() {
    int minResult = INT32_MAX;
    int maxResult = INT32_MIN;
    do{
        int result = nums[0];
        for(int i = 0; i < operators.size(); ++i){
            if(operators[i] == 0){
                result += nums[i + 1];
            }else if(operators[i] == 1){
                result -= nums[i + 1];
            }else if(operators[i] == 2){
                result *= nums[i + 1];
            }else {
                result /= nums[i + 1];
            }
        }
        minResult = std::min(minResult, result);
        maxResult = std::max(maxResult, result);
    }while(next_permutation(operators.begin(), operators.end()));

    cout << maxResult << '\n';
    cout << minResult;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve(); 
    
    return 0;
}
