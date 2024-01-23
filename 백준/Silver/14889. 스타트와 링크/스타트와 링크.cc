#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::prev_permutation;

typedef vector<vector<int>> matrix;

int N;
matrix board;
vector<bool> arr;

int answer = INT32_MAX;
int red = 0;
int blue = 0;

int calc (vector<int>& vec){
    int sum = 0;
    for(int i = 0; i < vec.size() - 1; ++i){
        for(int j = i + 1; j < vec.size(); ++j) {
            sum += board[vec[i]][vec[j]];
            sum += board[vec[j]][vec[i]];
        }
    }
    return sum;
}

void Solve() {
    do{
        vector<int> red;
        vector<int> blue;

        for(int i = 0; i < N; ++i) {
            if(arr[i]) red.push_back(i);
            else blue.push_back(i);
        }
        int a = calc(red);
        int b = calc(blue);
        answer = std::min(answer, std::abs(a - b));
    }while(prev_permutation(arr.begin(), arr.end()));
    cout << answer;
}

void Input() {
    cin >> N;
    board.resize(N, vector<int>(N));
    arr.resize(N, false);
    int tmp = N / 2;
    for(int i = 0; i < tmp; ++i) arr[i] = true;

    for(auto& y : board){
        for(auto& x : y){
            cin >> x;
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
