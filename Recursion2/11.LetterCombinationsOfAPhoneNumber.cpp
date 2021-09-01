#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<map>

using namespace std;

class Solution {
    
    void backtracking(map<int,vector<char> > &table, vector<string>& res, string& local, int index, const string& digits) {
        if(index==digits.size())
            res.push_back(local);
        else
            for(int i=0;i<table[digits[index]-'0'].size();i++) {
                local.push_back(table[digits[index]-'0'][i]);
                backtracking(table, res, local, index+1, digits);
                local.pop_back();
            }
    }
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> res;
        if(digits.size()==0) return res;
        string local;
        map<int,vector<char> > mp={
            {2,{'a','b','c'}},
            {3,{'d','e','f'}},
            {4,{'g','h','i'}},
            {5,{'j','k','l'}},
            {6,{'m','n','o'}},
            {7,{'p','q','r','s'}},
            {8,{'t','u','v'}},
            {9,{'w','x','y','z'}}
        };
        
        backtracking(mp,res,local,0,digits);
        return res;
    }
};