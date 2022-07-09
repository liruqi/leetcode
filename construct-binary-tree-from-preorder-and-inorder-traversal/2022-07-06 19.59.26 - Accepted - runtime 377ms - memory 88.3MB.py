# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(inorder) == 0:
            return None
        #print(preorder, inorder)
        rlen = inorder.index(preorder[0])

        return TreeNode(preorder[0], 
                      self.buildTree(preorder[1:rlen+1], inorder[:rlen]),
                      self.buildTree(preorder[rlen+1:], inorder[rlen+1:]),
                     )
        