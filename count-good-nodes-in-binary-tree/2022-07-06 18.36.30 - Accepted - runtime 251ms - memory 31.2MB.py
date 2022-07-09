# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    cnt = 0
    
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        q = []
        q.append(root)
        res = []
        self.cnt += 1
        
        while q:
            q2 = []
            lvl = []

            for tn in q:
                
                lvl.append(tn.val)
                if tn.left:
                    q2.append(tn.left)
                    if tn.left.val >= tn.val:
                        self.cnt+=1
                    else:
                        tn.left.val = tn.val
                if tn.right:
                    q2.append(tn.right)
                    if tn.right.val >= tn.val:
                        self.cnt+=1
                    else:
                        tn.right.val = tn.val
                
            q = q2
            res.append(lvl)

        return res
    
    def goodNodes(self, root: TreeNode) -> int:
        self.cnt = 0
        self.levelOrder(root)
        return self.cnt