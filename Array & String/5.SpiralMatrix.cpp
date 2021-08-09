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
        int i, direction = 0; //0 left to right, 1 top to down, 2 right to left, 3 down to top
        
        for (int top = 0, down = matrix.size()-1, left = 0, right = matrix[0].size()-1; top <= down && left <= right;){
            //0 left to right
            if(direction == 0){
                for (i = left; i <= right; i++)
                    v.push_back(matrix[top][i]);
                top++;
            }
            //1 top to down
            else if(direction==1){
                for (i = top; i <= down; i++)
                    v.push_back(matrix[i][right]);
                right--;
            }
            //2 right to left
            else if(direction==2){
                for (i = right; i >= left; i--)
                    v.push_back(matrix[down][i]);
                down--;
            }
            //3 down to top
            else if(direction==3){
                for (i = down; i >= top; i--)
                    v.push_back(matrix[i][left]);
                left++;
            }
            direction = (direction+1)%4;
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