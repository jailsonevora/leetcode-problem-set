#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        stack<int> stack;

        // using monotonic stack
        for (int i = 0; i < prices.size(); ++i)
        {   
            int dif = prices[i];
            while (!stack.empty() && prices[stack.top()] >= prices[i])
                prices[stack.top()] -= prices[i],
                    stack.pop();
            stack.push(i);
        }
        return prices;
    }
};

int main(){

    //ex1
    // vector<int>  prices = {8,4,6,2,3};

    //ex2
    vector<int>  prices = {1,2,3,4,5};

    Solution sl;
    for(auto it: sl.finalPrices(prices))
        cout << it;
}