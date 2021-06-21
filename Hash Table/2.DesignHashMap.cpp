#include<iostream>
#include<vector>

using namespace std;

class MyHashMap {
public:
    vector<int> hashMap;
    /** Initialize your data structure here. */
    MyHashMap() {
        hashMap = vector<int>(1000001, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        hashMap[key % 99510] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return hashMap[key % 99510];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        hashMap[key % 99510] = -1;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int key, value;
    cin >> key >> value;
    /**
    * Your MyHashMap object will be instantiated and called as such:*/
    MyHashMap* obj = new MyHashMap();
    obj->put(key,value);
    int param_2 = obj->get(key);
    obj->remove(key);
 
}