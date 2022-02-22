/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Trie {
    struct  TrieNode
    {
        char c;
        int count;
        int endsWord;
        TrieNode* children[26];
    };

    TrieNode* root;

    TrieNode *createNode(int index){
        
        TrieNode* newNode = new TrieNode;
        newNode->c = 'a'+index;
        newNode->count = newNode->endsWord = 0;
        
        for(int i = 0; i < 26; ++i)
            newNode->children[i] = nullptr;
        return newNode;
    }
    
public:
    Trie() {
        root = createNode('*'-'a');
    }
    
    void insert(string word) {
        
        TrieNode *curr = root;

        int index;
        for (int i = 0; word[i] != '\0'; i++)
        {
            index = word[i]-'a';
            if(curr->children[index] == nullptr)
                curr->children[index] = createNode(index);
            curr->children[index]->count += 1;

            // increment
            curr = curr->children[index];
        }
        curr->endsWord += 1;
    }
    
    bool search(string word) {

        TrieNode *curr = root;

        int index;
        for (int i = 0; word[i] != '\0'; i++)
        {
            index = word[i]-'a';
            if(curr->children[index] == nullptr)
                return false;
            
            // increment
            curr = curr->children[index];            
        }
        return curr->endsWord > 0;
    }
    
    bool startsWith(string prefix) {

        TrieNode *curr = root;

        int index;
        for (int i = 0; prefix[i] != '\0'; i++)
        {
            index = prefix[i]-'a';
            if(curr->children[index] == nullptr)
                return false;
            
            // increment 
            curr = curr->children[index];            
        }
        return curr->count > 0;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

