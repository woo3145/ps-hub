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

#define MOD 1000000
#define ull unsigned long long

typedef vector<vector<ull>> matrix;

matrix operator * (const matrix& a, const matrix& b) {
    matrix result(2, vector<ull>(2, 0ull));

    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k < 2; ++k){
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] %= MOD;
        }
    }
    return result;
}

matrix powMatrix(matrix& base, ull pow){
    matrix result = {{1, 0}, {0, 1}};

    while(0 < pow){
        if(pow & 1) result = base * result;
        base = base * base;
        pow >>= 1; 
    }

    return result;
}


ull N;

void Input() {
    cin >> N;
}

void Solve() {
    matrix fibo = {{1, 1}, {1, 0}};
    
    matrix result = powMatrix(fibo, N);

    cout << result[1][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve(); 
    
    return 0;
}
