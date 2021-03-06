#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    static int cmp(pair<string, int>& a, pair<string, int>& b)
    {
        return a.second > b.second;
    }

    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {

        unordered_map<string,int> mp;

        for (int i = 0; i < list1.size(); i++)
            mp.insert(make_pair(list1[i],i));

        vector<pair<string,int>> v;

        for (int i = 0; i < list2.size(); i++)
            if(mp.count(list2[i]))
                v.push_back(make_pair(list2[i], mp[list2[i]] + i));
        
        pair<string,int> min = *min_element(v.begin(), v.end(), 
            [](const pair<string,int>& lhs, const pair<string,int>& rhs) {
            return lhs.second < rhs.second;    
        });
        vector<string> result;
        for (pair<string,int>& rlt : v)
            if(min.second == rlt.second)
                result.push_back(rlt.first);
        return result;
    }

    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {

        unordered_map<string,int> mp;

        for (int i = 0; i < list1.size(); i++)
            mp.insert(make_pair(list1[i],i));

        vector<string> result;
        int min=INT_MAX, sum =0;

        for (int i = 0; i < list2.size(); i++){
            if(mp.count(list2[i]))
            {
                sum = mp[list2[i]] + i;
                if(sum<min){
                    result.clear();
                    result.push_back(list2[i]);
                    min = sum;
                }           
                else if(sum == min)
                    result.push_back(list2[i]);
            } 
        }        
        return result;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //vector<string> l1 = {"Shogun","Tapioca Express","Burger King","KFC"}, l2 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
    //vector<string> l1 = {"Shogun","Tapioca Express","Burger King","KFC"}, l2 = {"KFC","Shogun","Burger King"};
    //vector<string> l1 = {"Shogun","Tapioca Express","Burger King","KFC"}, l2 = {"KFC","Burger King","Tapioca Express","Shogun"};
    vector<string> l1 = {"Shogun","Tapioca Express","Burger King","KFC"}, l2 = {"KNN","KFC","Burger King","Tapioca Express","Shogun"};
    //vector<string> l1 = {"KFC"}, l2 = {"KFC"};

    Solution sl;
    sl.findRestaurant(l1,l2);
}