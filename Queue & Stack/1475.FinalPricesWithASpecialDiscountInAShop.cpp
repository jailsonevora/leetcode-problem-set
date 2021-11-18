#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {

public:
    vector<int> finalPrices(vector<int>& prices) {
        
        stack<int> stack;

        // using monotonic stack
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            while (!stack.empty() && stack.top() <= nums[i])
                stack.pop();

            ans.push_back(stack.empty() ? 0 : stack.top());
            stack.push(nums[i]);
        }

        reverse(ans.begin(), ans.end());
    }
    
};

int main(){

    //ex1
    vector<int>  prices = {8,4,6,2,3};

    //ex2
    //vector<int>  prices = {1,2,3,4,5};

    Solution sl;
    for(auto it: sl.finalPrices(prices))
        cout << it;
}