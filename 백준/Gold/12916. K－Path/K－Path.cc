#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

#define MOD 1000000007
#define ull unsigned long long

typedef vector<vector<ull>> matrix;


matrix operator * (const matrix& a, const matrix& b) {
    int Y = a.size();
    int X = a[0].size();
    matrix result(Y, vector<ull>(X, 0));

    for(int i = 0; i < Y; ++i){
        for(int j = 0; j < X; ++j){
            for(int k = 0; k < Y; ++k){
                result[i][j] += (a[i][k] % MOD) * (b[k][j] % MOD);
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}

matrix powMatrix(matrix& base, int pow){
    matrix result(base.size(), vector<ull>(base.size(), 0));

    for(int i = 0; i < base.size(); ++i){
        result[i][i] = 1;
    }

    while(pow){
        if(pow & 1) {
            result = result * base;
        }
        base = base * base;
        pow >>= 1;
    }

    return result;
}


int N, K;
matrix graph;

void Input() {
    cin >> N >> K;
    graph.assign(N, vector<ull>(N));

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> graph[i][j];
        }
    }
}

void Solve() {
    matrix result = powMatrix(graph, K);
    ull answer = 0;
    for(auto& y : result){
        for(auto& x : y){
            answer += x;
            answer %= MOD;
        }
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
