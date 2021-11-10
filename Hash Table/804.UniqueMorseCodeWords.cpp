#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        vector<string> fullTable = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
    "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> assciiToMorse;

        for(auto flStr: fullTable){
            string code;
            for(auto c: flStr)
                code += fullTable[c-'a'];
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