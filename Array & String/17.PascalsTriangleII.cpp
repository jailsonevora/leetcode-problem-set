#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<cmath>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        vector<vector<int>> result(34);
        for (int r = 0; r < 34; r++){
            result[r].resize(r+1);
            result[r][0] = result[r][r] = 1;
            if(r == rowIndex)
                    ans.push_back(result[r][0]);
            for (int c = 1; c < r; ++c){
                result[r][c] = result[r-1][c-1] + result[r-1][c];
                if(r == rowIndex)
                    ans.push_back(result[r][c]);
            }
            if(r == rowIndex && r !=0)
                    ans.push_back(result[r][r]);
        }
        return ans;  
    }

    vector<int> getRow(int r) {
        vector<int> res(r+1, 1); 
        for(int i=1; i<r; i++)
            res[i] = (res[i-1]*1LL*(r-i+1))/i;
        return res;
    }

    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return {1};
        
        auto prevRow = getRow(rowIndex - 1);
        vector<int> curRow(rowIndex + 1, 1);
        
        for (int i = 1; i < rowIndex; i++)
            curRow[i] = prevRow[i-1] + prevRow[i];
        
        return curRow;
    }
};


int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

   
    int rowIndex = 3;
    //int rowIndex = 0;
    //int rowIndex = 1;

   sl.getRow(rowIndex);
}