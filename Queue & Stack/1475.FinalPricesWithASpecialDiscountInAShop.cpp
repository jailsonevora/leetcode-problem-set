#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {

public:
    vector<int> finalPrices(vector<int>& prices) {
        
        stack<int> stack;
        vector<int> ans;

        // using monotonic stack
        for (int i = 0; i < prices.size(); ++i)
        {   
            int dif = prices[i];
            while (!stack.empty() && prices[i] <= stack.top()){
                dif = stack.top() - prices[i],
                    stack.pop();

            ans.push_back(dif);
            stack.push(prices[i]);
        }
        return ans;
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