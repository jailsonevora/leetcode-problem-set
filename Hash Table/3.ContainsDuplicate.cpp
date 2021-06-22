class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
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