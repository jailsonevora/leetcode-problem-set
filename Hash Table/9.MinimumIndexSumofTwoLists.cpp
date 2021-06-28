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

        pair<string,int> min = *min_element(v.begin(), v.end());
        
        vector<string> result;
        for (auto& rlt : v){
            if(min.second == rlt.second)
                result.push_back(rlt.first);
        }
        return result;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //vector<string> l1 = {"Shogun","Tapioca Express","Burger King","KFC"}, l2 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
    vector<string> l1 = {"Shogun","Tapioca Express","Burger King","KFC"}, l2 = {"KFC","Shogun","Burger King"};
    //vector<string> l1 = {"Shogun","Tapioca Express","Burger King","KFC"}, l2 = {"KFC","Burger King","Tapioca Express","Shogun"};
    //vector<string> l1 = {"Shogun","Tapioca Express","Burger King","KFC"}, l2 = {"KNN","KFC","Burger King","Tapioca Express","Shogun"};
    //vector<string> l1 = {"KFC"}, l2 = {"KFC"};

    Solution sl;
    sl.findRestaurant(l1,l2);
}