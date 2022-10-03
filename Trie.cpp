/*
https://leetcode.com/problems/implement-trie-prefix-tree/
Idea is to create a struct node with isTernimal indicating word ending here
and a pointer array for string address of childs(size depends upon req)
*/

struct Node{
    Node* links[26];
    bool isTerminal=false;
};
class Trie {
Node* root;
    bool containsKey(Node* node,char ch){
        return node->links[ch-'a']!=NULL;
    }
    
    Node* getNext(Node* node, char ch){
        return node->links[ch-'a'];
    }
    
    Node* createNewNode(Node* node, char ch){
        Node * newNode = new Node();
        node->links[ch-'a'] = newNode;
        return newNode;
    }
    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char ch:word){
            if(containsKey(node,ch)){
                node = getNext(node,ch);
            }
            else{
                node = createNewNode(node,ch);
            }
        }
        node->isTerminal = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(char ch:word){
            if(containsKey(node,ch)){
                node = getNext(node,ch);
            }
            else{
                return false;
            }
        }
        return node->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char ch:prefix){
            if(containsKey(node,ch)){
                node = getNext(node,ch);
            }
            else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
