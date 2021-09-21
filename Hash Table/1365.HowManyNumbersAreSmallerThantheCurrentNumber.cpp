#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    //string s = "abacbc";
    vector<int> nums = {1,2,3,1,1,3};

    Solution sl;
    cout << sl.numIdenticalPairs(nums);
}