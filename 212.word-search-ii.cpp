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

class Solution {
    
    struct TrieNode
    {
        char c;
        int endsWord;
        TrieNode* children[26];
    };

    TrieNode* createNode(int index){

        TrieNode* newNode = new TrieNode;
        newNode->c = 'a'+index;
        newNode->endsWord = 0;

        for (int i = 0; i < 26; i++)
            newNode->children[i] = nullptr;
        return newNode;
    }

    TrieNode* root = createNode('*'-'a');

    void insert(string word){
        
        TrieNode *curr = root;

        int index;
        for (int i = 0; word[i] != '\0'; i++)
        {
            index = word[i]-'a';
            if(!curr->children[index])
                curr->children[index] = createNode(index);

            curr = curr->children[index];
        }
        curr->endsWord += 1;
    }

    void dfsOnGrid(int m,int n,int r,int c,vector<vector<char>>& board,TrieNode* T,vector<string>& ans,string s)
    {
        if(r >= m || c >= n || r < 0 || c < 0 || board[r][c] == '/' || !(T->children[board[r][c]-'a']) )
            return;

        T = T->children[board[r][c]-'a'];

        s.push_back(board[r][c]);
        if(T->endsWord >0)
            ans.push_back(s);
                root->endsWord-=1;
        
        char ch = board[r][c];
        board[r][c]='/';        

        dfsOnGrid(m,n,r-1,c,board,T,ans,s); // up 
        dfsOnGrid(m,n,r+1,c,board,T,ans,s); // down
        dfsOnGrid(m,n,r,c-1,board,T,ans,s); // left
        dfsOnGrid(m,n,r,c+1,board,T,ans,s); // right

        board[r][c] = ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        // create a trie with those words
        for(string w: words)
            insert(w);

        TrieNode* temp=root;

        vector<string> ans;
        for (int r = 0; r < board.size(); r++)
            for (int c = 0; c < board[0].size(); c++)
                dfsOnGrid(board.size(),board[0].size(),r,c,board,temp,ans,"");
        return ans;
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
