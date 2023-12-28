#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define MAX 200000000
#define lint long long

using std::ios;
using std::cout;
using std::cin;
using std::vector;

struct Pos {
    lint y;
    lint x;
    Pos(lint _y, lint _x): y(_y), x(_x) {}
    ~Pos(){}
};

lint calcDist(const Pos& a, const Pos& b){
    return std::abs(a.y - b.y) + std::abs(a.x - b.x);
}

lint N;
vector<Pos> checkers;
vector<Pos> positions;

void Input() {
    cin >> N;
    std::set<lint> yList;
    std::set<lint> xList;
    lint y, x;
    for(lint i = 0; i < N; ++i){
        cin >> y >> x;
        checkers.emplace_back(y, x);
        yList.insert(y);
        xList.insert(x);
    }

    for(const auto& y : yList) {
        for(const auto& x : xList){
            positions.emplace_back(y, x);
        }
    }
}

void Solve() {
    vector<lint> answer;
    answer.assign(N, MAX);

    for(const auto& p : positions){
        // 다른 체커와 거리계산
        vector<lint> cache;
        cache.reserve(N);

        for(const auto& c : checkers){
            cache.push_back(calcDist(p, c));
        }

        std::sort(cache.begin(), cache.end());
        lint cnt = 0;
        for(size_t i = 0; i < N; ++i){
            cnt += cache[i];
            if(cnt < answer[i]) answer[i] = cnt;
        }
    }

    for(lint i = 0; i < N; ++i){
        cout << answer[i];
        if(i != N-1) cout << ' ';
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
