#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        bool goingUp = true;
        int i = 0;
        
        for (int r = 0, c = 0; r < matrix.size() && c < matrix[0].size();){
            if(c == matrix[0].size()-1 && (r != matrix.size()-1)){
                ++r;                
                v.push_back(matrix[r][c]);
            }
            else if(c > 0 && r == matrix[0].size()-1){
                --c;
                v.push_back(matrix[r][c]);
            }
            else if(c == 0 && r == matrix[0].size()-1){
                --r;
                v.push_back(matrix[r][c]);
            }
            else{
                v.push_back(matrix[r][c]);
                c++;
            }
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

    sl.spiralOrder(mat);
}