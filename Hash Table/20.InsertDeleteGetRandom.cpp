#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class RandomizedSet {
public:
    unordered_set<int> hashSet;
    /** Initialize your data structure here. */
    RandomizedSet() {
        hashSet.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        return hashSet.insert(val).second;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return hashSet.erase(val);          
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        auto iter = hashSet.begin();
        advance(iter, rand() % hashSet.size());
        return *iter;
    }
};

class RandomizedSet {    
    unordered_map<int,int> mp;
    vector<int> vec;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        vec.clear();
        mp.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(!mp.count(val)){            
            mp[val] = vec.size();
            vec.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.count(val)){
            vec[mp[val]]=vec.back();
            mp[vec.back()]=mp[val];
            vec.pop_back();
            mp.erase(val);
            return true;
        }
        return false;            
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int val = 10;
    cin >> val; 

    RandomizedSet* obj = new RandomizedSet();
    obj->insert(val);
    obj->remove(val);
    cout << obj->getRandom();
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */