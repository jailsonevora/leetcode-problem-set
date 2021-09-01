#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //sort(nums.begin(), nums.end());

        int head = 0, tail = nums.size() - 1;
        

        while(head < tail)
        {
            int midle = head + (tail + head) / 2;
        }
        

        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> v = {-1,0,3,5,9,12};

    Solution sl;
    sl.search(v,9);
}