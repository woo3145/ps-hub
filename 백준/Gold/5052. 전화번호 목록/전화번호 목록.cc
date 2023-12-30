#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::unordered_map;
using std::sort;
using std::min;


int T, N;
vector<string> nums;

void Input() {
    nums.clear();
    cin >> N;
    nums.reserve(N);
    for(int i = 0;i < N; ++i){
        string s;
        cin >> s;
        nums.push_back(s);
    }
}
void Solve() {
    sort(nums.begin(), nums.end());

    string answer = "YES";
    
    for(int i = 0; i < nums.size() - 1; ++i){
        int len = min(nums[i].length(), nums[i + 1].length());
        bool isSame = true;
        for(int j = 0; j < len; ++j){
            if(nums[i][j] != nums[i+1][j]){
                isSame = false;
                break;
            }
        }
        if(isSame){
            answer = "NO";
            break; 
        }
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;

    for(int i = 0; i < T; ++i){
        Input();
        Solve();   
    }
    
    return 0;
}
