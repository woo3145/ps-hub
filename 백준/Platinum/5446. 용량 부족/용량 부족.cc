#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::map;
using std::string;

struct TrieNode {
    bool end;
    bool removable;
    map<char, TrieNode*> children;

    TrieNode(bool _removable):end(false), removable(_removable){};
    ~TrieNode(){
        for(auto& n : children){
            if(n.second) delete n.second;
        }
    };
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode(true);
    };
    ~Trie(){
        delete root;
    }

    void insert(string& str, bool removable){
        TrieNode* cur = root;
        cur->removable = removable;
        for(auto& c : str){
            if(cur->children.find(c) == cur->children.end()){
                cur->children[c] = new TrieNode(removable);
            }
            cur = cur->children[c];
            cur->removable = removable;
        }
        if(removable){
            cur->end = true;
        }
    }
};

int N, M;
Trie* trie;

int Search (TrieNode* node){
    if(node->removable) return 1;
    int tmp = 0;
    if(node->end) ++tmp;
    for(auto& c : node->children){
        tmp += Search(c.second);
    }
    return tmp;
}

void Solve() {
    int answer = Search(trie->root);

    cout << answer << '\n';
}

void Input() {
    trie = new Trie();
    cin >> N;
    string s;
    for(int i = 0; i < N; ++i){
        cin >> s;
        trie->insert(s, 1);
    }
    cin >> M;
    for(int i = 0; i < M; ++i){
        cin >> s;
        trie->insert(s, 0);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for(int i = 0; i < T; ++i){
        Input();
        Solve();
    }
    
    return 0;
}
