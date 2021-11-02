#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

// two pointers techinic O(N3)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();  
        sort(nums.begin() , nums.end());  // sort the array to use the two pointers method
        
        vector<vector<int>> ans;  
        set<vector<int>> store;   // to store and remove the duplicate answers
		
        for(int i = 0 ; i < n; i++){		
            for(int j = i + 1; j < n ; j++){
			
                int new_target  =  target - nums[i] - nums[j];
                
                int left = j+1 , right = n-1;
                
                while(left < right){
				
                    int sum = nums[left] + nums[right];
                    
                    if(sum > new_target) 
                        right--;
                    else if(sum < new_target ) 
                        left++;
                    else
                        store.insert({nums[i] , nums[j] , nums[left] , nums[right]}),
                            left++,right--;
                }
            }
        }
		
        for(auto i : store)
            ans.push_back(i);  // store the answers in an array(ans)
		
        return ans;
    }
};

int main(){

    vector<int> nums{
        1,0,-1,0,-2,2
    };

    int target = 0;

    Solution sl;
    sl.fourSum(nums,target);

}