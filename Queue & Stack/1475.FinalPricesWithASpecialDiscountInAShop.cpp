#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {

public:
    vector<int> finalPrices(vector<int>& prices) {
        
        stack<int> stack;
        vector<int> ans;

        // using monotonic stack
        for (int i = prices.size() - 1; i >= 0; --i)
        {
            while (!stack.empty() && stack.top() <= prices[i])
                stack.pop();

            ans.push_back(stack.empty() ? prices[i] : stack.top());
            stack.push(prices[i]);
        }

        //reverse(ans.begin(), ans.end());
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