#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        vector<string> ans;

        int num = 1; //Current Element tells the element to be added in the stack, first element added will be 1
        
        for(int i=0; i < target.size(); i++){
            while(num!=target[i])//While we do not make current element equal to corresponding element in target array 
                ans.push_back("Push"),//We will simply push and pop those elements which are not in final target array 
                    ans.push_back("Pop"),
                        num++;
            
            ans.push_back("Push");//Pushing the target element in stack 
            num++;
        }
        return ans;
    }
};

int main(){

    //ex1
    vector<int> target = {1,3};
    int n = 3;

    // ex2
    // vector<int> target = {1,2,3};
    // int n = 3;

    Solution sl;
    for(auto it: sl.buildArray(target,n))
        cout << it <<" "; 
}