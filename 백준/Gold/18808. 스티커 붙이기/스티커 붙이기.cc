#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;

typedef vector<vector<int>> matrix;

int N, M, K;
vector<matrix> arr;
matrix board;

matrix rotate(matrix& mt){
    matrix tmp(mt[0].size(), vector<int>(mt.size(), 0));

    for(int i = 0; i < tmp.size(); ++i){
        for(int j = 0; j < tmp[0].size(); ++j){
            tmp[i][j] = mt[mt.size() - j - 1][i];
        }
    }
    return tmp;
}

bool check(matrix& piece, int i, int j, int pY, int pX) {
    for(int cy = 0; cy < pY; ++cy){
        for(int cx = 0; cx < pX; ++cx){
            if(piece[cy][cx] && board[i + cy][j + cx]) return true;
        }
    }
    return false;
}
void paint(matrix& piece, int i, int j, int pY, int pX) {
    for(int cy = 0; cy < pY; ++cy){
        for(int cx = 0; cx < pX; ++cx){
            if(piece[cy][cx]) {
                board[i + cy][j + cx] = 1;
            };
        }
    }
}

void Solve() {
    for(auto& piece : arr){
        for(int i = 0; i < 4; ++i){
            int pY = piece.size();
            int pX = piece[0].size();
            bool flag = false;
            for(int i = 0; i <= N - pY; ++i){
                for(int j = 0; j <= M - pX; ++j){
                    if(!check(piece, i, j, pY, pX)){
                        flag = true;
                        paint(piece, i, j, pY, pX);
                        break;
                    };
                }
                if(flag) break;
            }
            if(flag) break;
            piece = rotate(piece);
        }
    }
    int answer = 0;
    for(auto& y : board){
        for(auto& x : y){
            if(x == 1){
                ++answer;
            }
        }
    }
    cout << answer;
}

void Input() {
    cin >> N >> M >> K;
    board.resize(N, vector<int>(M, 0));
    arr.reserve(K);

    int y, x;
    for(int i = 0; i < K; ++i){
        cin >> y >> x;
        matrix tmp(y, vector<int>(x));
        for(auto& y : tmp){
            for(auto& x : y){
                cin >> x;
            }
        }
        arr.push_back(tmp);
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
