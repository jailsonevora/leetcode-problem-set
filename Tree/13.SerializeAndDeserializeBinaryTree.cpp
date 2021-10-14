#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#";
        return ""+ to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return pointer_deser(data);
        
    }
    TreeNode* pointer_deser(string& data)
    {
        if(data[0]=='#')
        {
            if(data.size()>1)
                data = data.substr(2);
            return NULL;
        }
        else{
            TreeNode* root = new TreeNode(helper(data));
            root->left = pointer_deser(data);
            root->right = pointer_deser(data);
            return root;
        }
    }
    int helper(string& data)
    {
        int ind = data.find(',');
        int val = stoi(data.substr(0, ind));
        data = data.substr(ind+1);
        return val;
    }
};