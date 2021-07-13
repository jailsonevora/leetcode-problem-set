#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    // int val = 3;
    // vector<int> v = {3,2,2,3};
    int val = 2; 
    vector<int> v = {0,1,2,2,3,0,4,2};

   cout << sl.removeElement(v,val) << "\n";
}