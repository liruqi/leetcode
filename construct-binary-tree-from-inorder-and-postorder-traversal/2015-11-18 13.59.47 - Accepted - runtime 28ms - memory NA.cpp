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
    int* inOrder;
    int* postOrder;
    TreeNode* buildTreeRecuresive(int* inorder, int *postorder, int n) {
        int rootv = postorder[n - 1];
        TreeNode* root = new TreeNode(rootv);
        for (int i=0; i<n; i++) {
            if (inorder[i] == rootv) {
                if (i>0) {
                root->left = buildTreeRecuresive(inorder, postorder, i);
                }
                
                if (i<n-1) {
                root->right = buildTreeRecuresive(inorder + i + 1, postorder+i, n-i-1);
                }
                break;
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // get last node of post order
        int n = inorder.size();
        inOrder = new int[n];
        postOrder = new int[n];
        
        for (int i=0; i<n; i++) {
            inOrder[i] = inorder[i];
            postOrder[i] = postorder[i];
        }
        
        if (n == 0) return NULL;
        
        return buildTreeRecuresive(inOrder, postOrder, n);
        
    }
};