# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        q = []
        q.append(root)
        res = []
        while q:
            lvl = []
            q2 = []
            for tn in q:
                lvl.append(tn.val)
                if tn.left:
                    q2.append(tn.left)
                if tn.right:
                    q2.append(tn.right)
            q = q2
            res.append(lvl)
        return res