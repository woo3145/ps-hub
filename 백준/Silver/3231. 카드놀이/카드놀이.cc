#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using std::ios;
using std::cout;
using std::cin;

using std::vector;

int N;
int arr[100001];

void Solve() {
    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        if (arr[i] < arr[i - 1]) ++answer;
    }
    cout << answer;
}

void Input() {
    cin >> N;

    int idx;
    for (int i = 0; i < N; ++i) {
        cin >> idx;
        arr[idx] = i;
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
