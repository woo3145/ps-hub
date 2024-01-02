#include <iostream>
#include <vector>
#include <algorithm>

using std::ios;
using std::cout;
using std::cin;
using std::vector;

struct Edge {
    int from, to, cost;

    Edge(){}
    ~Edge(){}
};

int N, C, M;
vector<Edge> edges; 

void Input() {
    cin >> N >> C >> M;
    edges.resize(M);

    for(auto& e : edges){
        cin >> e.from >> e.to >> e.cost;
    }
}

// 4 40
// 6
// 3 4 20
// 1 2 10
// 1 3 20
// 1 4 30
// 2 3 10
// 2 4 20

void Solve() {
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        if(a.to == b.to){
            return a.from < b.from;
        }
        return a.to < b.to;
    });
    // 배송시 각 마을에서의 무게
    vector<int> cache;
    cache.assign(N + 1, 0);

    int answer = 0;

    for(auto& e : edges){
        int maxCost = 0;
        for(int i = e.from; i < e.to; ++i){
            maxCost = maxCost < cache[i] ? cache[i] : maxCost;
        }

        // 조건 3: 박스들 중 일부만 배송할 수도 있다.
        int rest = C - maxCost; // 트럭 남은공간
        int box = rest < e.cost ? rest : e.cost;
        answer += box;

        for(int i = e.from; i < e.to; ++i){
            cache[i] += box;
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
