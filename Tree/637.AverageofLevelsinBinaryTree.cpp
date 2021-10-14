#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
    // level order traversal with bfs
    vector<double> bfs(TreeNode* root){

        queue<TreeNode*> queue;
        vector<double> avg;

        queue.push(root);

        while (!queue.empty())
        {
            int size = queue.size();
            double sum = 0;

            for(int i = 0; i < size; i++)
            {
                TreeNode* tmp = queue.front();
                queue.pop();

                if(tmp->left)
                    queue.push(tmp->left);

                if(tmp->right)
                    queue.push(tmp->right);
                
                sum += tmp->val;
            }
            avg.push_back(sum/(double)size);
        }
        return avg;
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        return bfs(root);
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    // vector<int> preOrder = {1,0,0,1,1,0,1};
    // vector<int> inOrder = {0,1,0,1,0,1,1};

    // BuildTreeFromPreOrderArray bl;
    // TreeNode* root = bl.buildTree(preOrder, inOrder);

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    //root->left->left = new TreeNode(15);
    //root->left->right = new TreeNode(1);

    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);

    Solution sl;
    sl.averageOfLevels(root);
}