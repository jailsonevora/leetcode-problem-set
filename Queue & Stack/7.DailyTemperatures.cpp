#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;
    vector<int> s {73,74,75,71,69,72,76,73};
    //vector<int> s {30,40,50,60};
    // vector<int> s {30,60,90};

   for(auto& vec : sl.dailyTemperatures(s))
    cout << vec << "\n";
}