#include<iostream>
#include<set>
#include<stack>
#include<vector>

using namespace std;

class Solution {
    void DFS(vector<vector<int>> &image, int sr, int sc, int newColor, int r, int c, int source){
        if (sr < 0 || sr >= r || sc < 0 || sc >= c)
            return;
        
        image[sr][sc] = '2';

        //recursive call to 4 adjacent directions
        DFS(image, sr - 1, sc, newColor, r, c, source);
        DFS(image, sr + 1, sc, newColor, r, c, source);
        DFS(image, sr, sc + 1, newColor,r, c, source);
        DFS(image, sr, sc - 1, newColor,r, c, source);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
    }
};