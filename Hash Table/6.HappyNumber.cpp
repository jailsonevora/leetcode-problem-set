#include<iostream>
#include<unordered_set>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> happy;
        happy.insert(n);

        while (n != 1)
        {   
            int w = 0;     
            while (n)
            {
                w += (pow((n%10),2));
                n/=10;
            }
            n = w;
            if (happy.find(n) != happy.end())
                return false;

            happy.insert(n);            
        }
        return true;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;

    Solution s;
    s.isHappy(n); 
}