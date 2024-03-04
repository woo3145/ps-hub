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

int N;
vector<long long> positiveArr;
vector<long long> nagativeArr;

void Solve() {
    long long answer = 0;
    std::sort(positiveArr.begin(), positiveArr.end());
    std::sort(nagativeArr.rbegin(), nagativeArr.rend());
  
    while(1 < positiveArr.size()){
        long long a = positiveArr.back();
        positiveArr.pop_back();
        long long b = positiveArr.back();
        positiveArr.pop_back();

        if(a == 1 || b == 1){
            answer += (a + b);
        }else{
            answer += a * b;
        }
    }

    while(1 < nagativeArr.size()){
        long long a = nagativeArr.back();
        nagativeArr.pop_back();
        long long b = nagativeArr.back();
        nagativeArr.pop_back();

        answer += a * b;
    }

    if(!positiveArr.empty()) answer += positiveArr.back();
    if(!nagativeArr.empty()) answer += nagativeArr.back();

    cout << answer;
}

void Input() {
    cin >> N;
    
    for(int i = 0; i < N; ++i){
        long long n;
        cin >> n;
        if(0 < n){
            positiveArr.push_back(n);
        }else{
            nagativeArr.push_back(n);
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
