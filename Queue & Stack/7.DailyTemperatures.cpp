#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<unordered_map<int,int>> stck;
        int ans[temperatures.size()]{0};

        unordered_map<int, int> mp;
        mp.insert(make_pair(temperatures.size()-1,temperatures[temperatures.size()-1]));
        stck.push(mp);

        for (int i = temperatures.size()-2; i >= 0; --i)
        {
            unordered_map<int, int> sTop = stck.top();
            for (unordered_map<int,int>::iterator it=sTop.begin(); it!=sTop.end(); ++it)
            {

                if( it->second < temperatures[i]){
                    stck.pop();
                    unordered_map<int, int> mpTemp;
                    mpTemp.insert(make_pair(i,temperatures[i]));
                    stck.push(mpTemp);
                }
                else{
                    ans[i] = it->first - i;
                    unordered_map<int, int> mpTemp;
                    mpTemp.insert(make_pair(i,temperatures[i]));
                    stck.push(mpTemp);
                }
            }   
        } 
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