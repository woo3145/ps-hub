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
vector<int> stock;
 
void Solve() {
    long long answer = 0;

    int maxN = -1;
    for(int i = stock.size() - 1; 0 <= i; --i){
        if(maxN < stock[i]){
            maxN = stock[i];
        }else{
            answer += (maxN - stock[i]);
        }
    }
    cout << answer << '\n';
}

void Input() {
    cin >> N;
    stock.clear();
    stock.resize(N);
    for(auto& n : stock){
        cin >> n;
    }
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
