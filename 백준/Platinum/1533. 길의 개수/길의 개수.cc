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

#define MOD 1000003
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


int N, S, E, T;
matrix graph;

void Input() {
    cin >> N >> S >> E >> T;
    graph.assign(N * 5, vector<ull>(N * 5));

    // 가중치 5 반영
    for(int i = 0; i < N; ++i){
        for(int j = 1; j < 5; ++j){
            // 추가되는 노드는 이전 노드를 가르킴
            graph[i * 5 + j][i * 5 + j - 1] = 1;
        }
    }

    for(int i = 0; i < N; ++i){
        string str;
        cin >> str;
        for(int j = 0; j < N; ++j){
            if(str[j] == '0') continue;
            graph[i * 5][j * 5 + (str[j] - '0') - 1] = 1;
        }
    }
}

void Solve() {
    matrix answer = powMatrix(graph, T);

    cout << answer[(S-1) * 5][(E-1)*5];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve(); 
    
    return 0;
}
