#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MyHashSet {
    int size;
    vector<vector<int>> buckets;

    int hashFunction(int key){
        return key % size;
    }
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        size = 15000;
        buckets = vector<vector<int>>(size, vector<int>{});        
    }
    
    void add(int key) {
        int i = hashFunction(key);
        if(find(buckets[i].begin(), buckets[i].end(), key) == buckets[i].end())
            buckets[i].push_back(key);                
    }
    
    void remove(int key) {
        int i = hashFunction(key);
        auto it = find(buckets[i].begin(), buckets[i].end(), key);
        if (it != buckets[i].end())
            buckets[i].erase(it);  
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int i = hashFunction(key);
        if(find(buckets[i].begin(), buckets[i].end(), key) != buckets[i].end())
            return true;
        return false;  
    }
};

class MyHashSet2 {
public:
    vector<bool> hashSet;
    
    /** Initialize your data structure here. */
    MyHashSet2() {
        hashSet = vector<bool>(1000001, false);
    }
    
    void add(int key) {
        hashSet[key] = true;
    }
    
    void remove(int key) {
        hashSet[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hashSet[key];
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int key = -1;
    cin >> key; 

    MyHashSet* obj = new MyHashSet();
    obj->add(key);
    obj->remove(key);
    bool param_3 = obj->contains(key);
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */