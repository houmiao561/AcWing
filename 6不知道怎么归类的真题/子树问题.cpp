/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
    public: 
        bool isSubtree(TreeNode* s, TreeNode* t) {
            if (s == NULL) return false;
            if (t == NULL) return true;
            if ( check(s,t) ) return true;
            bool x = isSubtree(s->left,t) || isSubtree(s->right,t);
            if (x==true) return true;
            return false;
        }
        bool check(TreeNode* s, TreeNode* t) {
            if ( s == NULL && t == NULL ) return true;
            if ( s == NULL || t == NULL ) return false;
            if ( s->val != t->val ) return false;
            bool left = check(s->left,t->left);
            bool right = check(s->right,t->right);
            if (right && left) return true;
            return false;
        }
};