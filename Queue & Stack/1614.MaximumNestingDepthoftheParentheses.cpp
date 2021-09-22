#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    //vector<int> students {1,1,1,0,0,1}, sandwiches {1,0,0,0,1,1};
    vector<int> students {1,1,1,0,0,1}, sandwiches {1,0,0,0,1,1};

    Solution sl;

    cout << sl.countStudents(students, sandwiches);

}