#include <iostream>
#include <algorithm>
#include <vector>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;

int L, K, C;
vector<int> points;

void Input() {
    cin >> L >> K >> C;
    points.resize(K);

    for(auto& p : points){
        cin >> p;
    }
}

pair<int, int> cutSimulate(int size, const vector<int>& units) {
    int count = 0;
    int curSize = 0;

    for(auto it = units.rbegin(); it != units.rend(); ++it) {
        curSize += *it;
        
        if(size < curSize){
            ++count;
            curSize = *it;
        }
    }
    // 자를 횟수가 남았으면 젤 앞에꺼 자름
    if(count < C){
        curSize = units[0];
    }

    return {count, curSize};
}

void Solve() {
    // 처음과 마지막의 조각크기를 위해 추가
    points.push_back(0); 
    points.push_back(L); 
    std::sort(points.begin(), points.end());

    int longestUnit = 0;

    // 모든 지점을 잘랐을 경우 각 크기를 미리 계산
    vector<int> units;
    units.resize(K + 1);
    for(int i = 0; i < K + 1; ++i){
        units[i] = points[i + 1] - points[i];
        if(longestUnit < units[i]) longestUnit = units[i];
    }

    int answerSize = 0;
    int answerPoint = 0;

    int left = 0;
    int right = L;

    while(left <= right){
        int mid = (left + right) / 2;

        if(longestUnit > mid) {
            // 현재 단위로 자를 수 없는 경우
            left = mid + 1;
            continue;
        }

        pair<int, int> result = cutSimulate(mid, units);

        if(result.first <= C){
            right = mid - 1;
            answerSize = mid;
            answerPoint = result.second;
        }else{
            left = mid + 1;
        }
    }

    cout << answerSize << ' ' << answerPoint;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();   
    
    return 0;
}
