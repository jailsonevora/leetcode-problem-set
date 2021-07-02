#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


class RandomizedSet {
public:
    vector<bool> hashSet;
    /** Initialize your data structure here. */
    RandomizedSet() {
        hashSet = vector<bool>(1000001, false);
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        hashSet[rand()] = val;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return hashSet[rand()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */