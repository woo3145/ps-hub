#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::unordered_map;
using std::sort;

struct TrieNode {
    bool isEnd;
    unordered_map<char, TrieNode*> children;
    TrieNode():isEnd(false) {};
    ~TrieNode(){};
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    };
    ~Trie(){};
    
    bool insert(const string& str){
        TrieNode* current = root;

        for(const char& c : str){
            if(current->children.find(c) == current->children.end()){
                current->children[c] = new TrieNode();
            }
            if(current->isEnd) return false;
            current = current->children[c];
        }
        current->isEnd = true;
        return true;
    };
};

int T, N;
vector<string> nums;


void Input() {
    nums.clear();
    cin >> N;
    nums.reserve(N);
    for(int i = 0;i < N; ++i){
        string s;
        cin >> s;
        nums.push_back(s);
    }
}
void Solve() {
    // 문자열 길이순 정렬
    sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
        if(a.length() == b.length()){
            return a < b;
        }
        return a.length() < b.length();
    });

    Trie trie;
    string answer = "YES";
    
    for(const auto& s : nums){
        if(!trie.insert(s)) {
            answer = "NO";
            break; 
        }
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;

    for(int i = 0; i < T; ++i){
        Input();
        Solve();   
    }
    
    return 0;
}
