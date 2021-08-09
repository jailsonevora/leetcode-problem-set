#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> v;
        bool goingUp = true;
        int i = 0;
        
        for (int r = 0, c = 0; r < mat.size() && c < mat[0].size();){
            if(goingUp){
                while(r > 0 && c < mat[0].size()-1){
                    v.push_back(mat[r][c]);
                    --r, c++;
                }
                v.push_back(mat[r][c]);
                (c == mat[0].size()-1) ?  ++r : ++c;                
            }
            else{
                while(c > 0 && r < mat.size()-1){
                    v.push_back(mat[r][c]);
                    ++r, c--;
                }
                v.push_back(mat[r][c]);
                (r == mat.size()-1) ?  ++c : ++r;   
            }
            // or down
            goingUp = !goingUp;
        }
        return v;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;
    vector<vector<int>> mat = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    sl.findDiagonalOrder(mat);
}