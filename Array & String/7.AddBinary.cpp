#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<string>
#include<bitset>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int sum = 0;

        for (int i = a.size()-1, j = b.size()-1; i >= 0 || j >= 0 || sum==1; --i, --j)
        {
            sum +=( (i >= 0) ? a[i] - '0': 0);
            sum +=( (j >= 0) ? b[j] - '0': 0);

            ans = char(sum % 2 + '0') + ans;

            sum/=2; 
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    sl.addBinary("11","1");
}