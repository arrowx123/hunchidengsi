// 211_Add_and_Search_Word
// trie
const int alphaSize = 26;
struct Node{
    bool end;
    Node *children[26];
    Node(){
        end = false;
        for(int i = 0; i < alphaSize; i ++)
            children[i] = nullptr;
    }
};
class WordDictionary {
private:
    Node *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *node = root;
        for(int i = 0; i < word.size(); i ++){
            int ch = word[i] - 'a';
            if(!node->children[ch])
                node->children[ch] = new Node();
            node = node->children[ch];
        }
        node->end = true;
    }
    
    bool searchUtil(string word, Node *node){
        for(int i = 0; i < word.size(); i ++){
            if(word[i] == '.'){
                for(int j = 0; j < alphaSize; j ++){
                    if(node->children[j]){
                        if(searchUtil(word.substr(i + 1), node->children[j]))
                            return true;
                    }
                }
                return false;
            }
            
            int ch = word[i] - 'a';
            if(!node->children[ch])
                return false;
            node = node->children[ch];
        }
        return node->end;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        Node *node = root;
        return searchUtil(word, node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
