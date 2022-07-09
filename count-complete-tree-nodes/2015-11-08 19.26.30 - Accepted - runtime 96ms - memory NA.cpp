/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        int h = height(root);
        if (h == 0) return 0;
        
        int cnt = 0;
        TreeNode* it = root;
        while (it) {
            h --;
            cnt += 1; // add self
            int rh = height(it->right);
            if (rh == h) {
                cnt += (1 << rh) - 1;
                it = it->right;
            } else {
                cnt += (1 << rh) - 1;
                it = it->left;
            }
        }
        return cnt;
    }
    
    int height (TreeNode* root) {
        int cnt = 0;
        while (root) {
            cnt++;
            root = root->left;
        }
        return cnt;
    }
};