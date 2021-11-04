#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {

        unordered_set<string> panagram;

        for (auto s : sentence)
        {
            /* code */
        }
        
        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    string s = "thequickbrownfoxjumpsoverthelazydog";

    Solution sl;
    cout << sl.checkIfPangram(s);
}