/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    TreeNode *cur = NULL;
    stack<TreeNode *> ts;

public:
    BSTIterator(TreeNode *root) {
        cur = root;        
    }

    // return whether we have a next smallest number
    bool hasNext() {
        return (!ts.empty() || cur != NULL);
    }

    // return the next smallest number
    int next() {
        while (cur) {
            ts.push(cur);
            cur = cur->left;
        }
        cur = ts.top(); ts.pop();
        int ans = cur->val;
        cur = cur->right;
        return ans;
    }
};


/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */