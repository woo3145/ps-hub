#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::map;

struct TrieNode {
    int isEnd;
    map<char, TrieNode*> children;

    TrieNode():isEnd(0){}
    ~TrieNode(){}
};

class Trie {
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    ~Trie(){}

    string insert(const string& str) {
        TrieNode* current = root;
        string ret = "";
        bool flag = true;

        for(const char& c : str){
            if(flag) ret += c;
            if(current->children.find(c) == current->children.end()){
                flag = false;
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEnd += 1;
        if(1 < current->isEnd){
            ret += std::to_string(current->isEnd);
        }

        return ret;
    }
};

int N;
vector<string> strings;

void Input() {
    cin >> N;
    strings.reserve(N);
    string s;
    for(int i = 0; i < N; ++i){
        cin >> s;
        strings.push_back(s);
    }
}

void Solve() {
    Trie trie;
    vector<string> answer;
    answer.reserve(N);
    for(const string& str : strings){
        answer.push_back(trie.insert(str));
    }

    for(const auto& s : answer){
        cout << s << '\n';
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
