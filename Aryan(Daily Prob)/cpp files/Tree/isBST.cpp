#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Pair
{
    public:
    int mx;
    int mn;
    bool isBST;
};
class Solution {
public:
    Pair helper(TreeNode* root)
    {
        Pair p;
        if(root->left==NULL && root->right==NULL)
        {
            p.mn = root->val;
            p.mx= root->val;
            p.isBST = true;
            return p;
        }
        else if(root->right==NULL)
        {
            p.mx = root->val;
            
            Pair ls = helper(root->left);
            
            if(ls.isBST && root->val > ls.mx)
            {
                p.mn = ls.mn;
                p.isBST = true;
            }
            else
            {
                p.isBST = false;
                p.mn = ls.mn;
            }
            return p;
        }
        else if(root->left == NULL)
        {
            p.mn = root->val;
            
            Pair rs = helper(root->right);
            
            if(rs.isBST && root->val < rs.mn)
            {
                p.mx = rs.mx;
                p.isBST = true;
            }
            else
            {
                p.isBST = false;
                p.mx = rs.mx;
            }
            return p;
        }
        
        Pair ls = helper(root->left);
        Pair rs = helper(root->right);
        
        if(ls.isBST && rs.isBST && root->val > ls.mx && root->val < rs.mn)
        {
            p.isBST = true;
            p.mn = ls.mn;
            p.mx = rs.mx;
        }
        else
        {
            p.isBST = false;
            p.mn = ls.mn;
            p.mx = rs.mx;
        }
        return p;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root).isBST;   
    }
};