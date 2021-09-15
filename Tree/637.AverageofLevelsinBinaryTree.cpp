#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>

using namespace std;

/**
 * Definition for a binary tree node.
 **/ 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 
class BuildTreeFromPreOrderArray {
    TreeNode* buildTree(vector<int>& preorder, int p1, int p2, vector<int>& inorder, int i1, int i2) {
        if(p1 > p2)
            return nullptr;
        
        TreeNode *root = new TreeNode(preorder[p1]);
        int i = i1;
        while (i <= i2) {
            if (inorder[i] == root->val) break;
            i ++;
        }

        int diff = i - i1 - 1;
        p1++;
        
        root->left = buildTree(preorder, p1, p1 + diff, inorder, i1, i1 + diff);
        root->right = buildTree(preorder, p1 + diff + 1, p2, inorder, i + 1,  i2);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!inorder.size())
            return nullptr;
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};

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