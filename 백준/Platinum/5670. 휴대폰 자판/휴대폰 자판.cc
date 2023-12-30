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
    bool isEnd;
    map<char, TrieNode*> children;

    TrieNode():isEnd(false){}
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

    void insert(string& str) {
        TrieNode* current = root;

        for(const char& c : str){
            if(current->children.find(c) == current->children.end()){
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEnd = true;
    }
    
    int search(string& str){
        int count = 0;
        TrieNode* current = root->children[str[0]];

        for(int i = 1; i < str.length(); ++i){
            while(i < str.length() && !current->isEnd && current->children.size() == 1){
                current = current->children[str[i]];
                ++count;
                ++i;
            }
            current = current->children[str[i]];
        }

        return str.length() - count;
    }
};

int N;
vector<string> strings;

void Input() {
    strings.clear();
    string s;
    for(int i = 0; i < N; ++i){
        cin >> s;
        strings.push_back(s);
    }
}
void Solve() {
    Trie trie;
    float answer = 0;

    for(auto& s : strings){
        trie.insert(s);
    }

    for(auto& s : strings){
        answer += trie.search(s);
    }
    float result = answer / strings.size();
    
    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << std::fixed;
    cout.precision(2);
    
    while(cin >> N){
        Input();
        Solve();
    }   
    
    return 0;
}
