# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
INF=40000 * 1000
class Solution:
    mpv = -INF
    def maxPathSumR(self, root):
        if not root:
            return [-INF,-INF]
        lv = self.maxPathSumR(root.left)
        rv = self.maxPathSumR(root.right)
        spv = root.val+max(lv[0], rv[0], 0)
        fpv = root.val+max(lv[0],0)+max(rv[0],0)
        if self.mpv < fpv:
            self.mpv = fpv
        #print (root.val, '->', [spv, fpv])
        return [spv, fpv]
    
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.mpv = -INF
        r = self.maxPathSumR(root)
        return max(self.mpv,r[0])