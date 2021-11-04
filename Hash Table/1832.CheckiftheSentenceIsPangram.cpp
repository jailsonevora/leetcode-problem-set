#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;


int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    //string s = "abacbc";
    string s = "aaabb";

    Solution sl;
    cout << sl.areOccurrencesEqual(s);
}