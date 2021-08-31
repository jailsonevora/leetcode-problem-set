#include<iostream>
#include<vector>
#include <string.h>

using namespace std;

class Solution {
    int dfs(bool columns[], bool d1[], bool d2[], int n, int r){
        if(r==n){
            return 1;
        }
        int tot=0;
        for(int i=0;i<n;i++){
            if(!columns[i] && !d1[i+r] && !d2[r-i+n-1]){
                columns[i]=1;
                d1[i+r]=1;
                d2[r-i+n-1]=1;
                tot+=dfs(columns,d1,d2,n,r+1);
                columns[i]=0;
                d1[i+r]=0;
                d2[r-i+n-1]=0;
            }
        }
        return tot;
    }
public:
    int totalNQueens(int n) {

        bool columns[n], d1[2*n-1], d2[2*n-1];

        memset(columns,0,sizeof(columns));
        memset(d1,0,sizeof(d1));
        memset(d2,0,sizeof(d2));
        
        return dfs(columns,d1,d2,n,0);
    }
};