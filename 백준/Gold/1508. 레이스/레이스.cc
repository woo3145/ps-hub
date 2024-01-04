#include <iostream>
#include <algorithm>
#include <vector>

using std::ios;
using std::cout;
using std::cin;
using std::vector;

int N, M, K;
vector<int> points;

void Input() {
    cin >> N >> M >> K;
    points.resize(K);

    for(auto& p : points){
        cin >> p;
    }
}

// 11 3 4
// 0 5 10 11

void Solve() {
    int maxGap = 0;

    int left = 0;
    int right = points.back() - points.front();

    while(left <= right){
        int mid = (left + right) / 2;

        int cnt = 1;
        int prevPoint = points[0];

        for(int i = 1; i < points.size(); ++i){
            if(points[i] - prevPoint < mid) continue;
            ++cnt;
            prevPoint = points[i];
        }

        if(M <= cnt){
            left = mid + 1;
            maxGap = mid;
        }else{
            right = mid -1;
        }
    }

    cout << "1";
    int count = 1;
    int prevPoint = points[0];
    for(int i = 1; i < K; ++i){
        if(count < M && maxGap <= points[i] - prevPoint){
            cout << "1";
            ++count;
            prevPoint = points[i];
        }else{
            cout << "0";
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
