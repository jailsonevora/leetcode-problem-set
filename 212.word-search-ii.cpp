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
        int endsWord;
        TrieNode* children[26];
    };

    TrieNode* root;

    TrieNode* createNode(int index){

        TrieNode* newNode = new TrieNode;
        newNode->c = 'a'+index;
        newNode->endsWord = 0;

        for (int i = 0; i < 26; i++)
            newNode->children[i] = nullptr;
        return newNode;
    }
public:

    Trie(){
        root = createNode('*'-'a');
    }

    
    
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
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
