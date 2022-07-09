# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.infmin = min(root.val, 0) - 1
        self.can = root.val
        self.MaxDownwardSum(root)
        return self.can
    
    def MaxDownwardSum(self, root: TreeNode):
        if not root:
            return self.infmin
        self.can = max(self.can, root.val)

        lmds = self.MaxDownwardSum(root.left)
        rmds = self.MaxDownwardSum(root.right)
        mds = max(lmds, rmds)
        self.can = max(self.can, mds + root.val)
        self.can = max(self.can, lmds + rmds + root.val)
        if mds <= 0 or root.val <= 0:
            return max(mds + root.val, root.val)
        return mds + root.val