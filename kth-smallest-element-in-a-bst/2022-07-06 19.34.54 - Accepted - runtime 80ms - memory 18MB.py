# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root: TreeNode, k: int):
        v = True
        cnt = 1
        if root.left:
            r = self.dfs(root.left, k)
            cnt += r[1]
            if (r[0] != None):
                return r
            else:
                k -= r[1]
        
        if k<=1:
            return [root.val, cnt]
        k -= 1
        
        if root.right:
            r =  self.dfs(root.right, k)
            if (r[0] != None):
                return r
            else:
                k -= r[1]
                cnt += r[1]
        return [None, cnt]
    
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        r = self.dfs(root,k)
        return r[0]
    