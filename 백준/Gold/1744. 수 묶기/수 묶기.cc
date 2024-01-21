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

int T;
int N;
vector<int> positive;
vector<int> negative;
vector<int> zero;
int answer = 0;
 
void Solve() {
    std::sort(positive.rbegin(), positive.rend());
    std::sort(negative.begin(), negative.end());

    if(!positive.empty() && positive.size() % 2 == 1){
        answer += positive.back();
        positive.pop_back();
    }
    if(!negative.empty() && negative.size() % 2 == 1){
        if(zero.empty()){
            answer += negative.back();
        }
        negative.pop_back();
    }

    while(!positive.empty()){
        int a = positive.back();
        positive.pop_back();
        int b = positive.back();
        positive.pop_back();
        answer += a*b;
    }
    while(!negative.empty()){
        int a = negative.back();
        negative.pop_back();
        int b = negative.back();
        negative.pop_back();
        answer += a*b;
    }

    cout << answer;
}

void Input() {
    cin >> N;
    int t;
    for(int i = 0; i < N; ++i){
        cin >> t;
        if(t == 1){
            answer += 1;
        }else if(t == 0){
            zero.push_back(t);
        }else if(0 < t){
            positive.push_back(t);
        }else{
            negative.push_back(t);
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
