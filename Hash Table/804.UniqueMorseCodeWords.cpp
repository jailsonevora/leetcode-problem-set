#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

class Solution {
    vector<string> fullTable = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
    "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {


        
    }
};

int main(){

    vector<string> words = {"gin","zen","gig","msg"},
    fullTable = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
    "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    Solution sl;
    cout << sl.uniqueMorseRepresentations(words);
}