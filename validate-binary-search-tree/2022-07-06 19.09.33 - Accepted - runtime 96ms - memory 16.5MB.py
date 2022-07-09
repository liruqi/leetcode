# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBSTRange(self, root: TreeNode, rg) -> bool:
        if rg[0]!=None:
            if root.val <= rg[0]:
                return False
        if rg[1]!=None:
            if root.val >= rg[1]:
                return False
        
        v = True
        if root.left:
            r = [rg[0], root.val]
            v = v and self.isValidBSTRange(root.left, r)
        if root.right:
            r = [ root.val, rg[1]]
            v = v and   self.isValidBSTRange(root.right, r)
        return v
    
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        return self.isValidBSTRange(root, [None, None])