#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        vector<string> table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
    "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> assciiToMorse;

        for(auto w: words){
            string code;
            for(auto c: w)
                code += table[c - 'a'];
            assciiToMorse.insert(code);
        }
        return assciiToMorse.size();        
    }
};

int main(){

    vector<string> words = {"gin","zen","gig","msg"};

    Solution sl;
    cout << sl.uniqueMorseRepresentations(words);
}