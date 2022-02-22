/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * {212} Word Search II
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Trie{
    struct TrieNode
    {
        char c;
        int count;
        int endsWord;
        TrieNode* children[26];
    };

    TrieNode* root;

    TrieNode* createNode(int index){

        TrieNode* newNode = new TrieNode;
        newNode->c = 'a'+index;
        newNode->count = newNode->endsWord = 0;

        for (int i = 0; i < 26; i++)
            newNode->children[i] = nullptr;
        return newNode;
    }
public:

    Trie(){
        root = createNode('*'-'a');
    }

    void insert(string word){
        
        TrieNode *curr = root;

        int index;
        for (int i = 0; word[i] != '\0'; i++)
        {
            index = word[i]-'a';
            if(!curr->children[index])
                curr->children[index] = createNode(index);
            curr->children[index]->count += 1;

            curr = curr->children[index];
        }
        curr->endsWord += 1;
    }

    bool startsWith(string prefix){
        
        TrieNode *curr = root;

        int index;
        for (int i = 0; prefix[i] != '\0'; i++)
        {
            index = prefix[i]-'a';
            if(!curr->children[index])
                return true;

            curr = curr->children[index];
        }
        return curr->count > 0;
    }  
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        // create a trie with those words
        Trie* newT = new Trie();


    }
};
// @lc code=end
int main(){

    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    }; 
    vector<string> words = {"oath","pea","eat","rain"};

    Solution sl;
    sl.findWords(board,words);
}
