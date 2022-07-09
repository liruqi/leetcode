# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

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
                if tn:
                    lvl.append("*" if tn=="*" else tn.val)
                    if tn=="*":
                        continue
                    if tn.left:
                        q2.append(tn.left)
                    else:
                        q2.append("*")
                    if tn.right:
                        q2.append(tn.right)
                    else:
                        q2.append("*")
            q = q2
            res.append(lvl)
        return res
    
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        lo = self.levelOrder(root)
        #print (lo)
        return json.dumps(lo)
    

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        lo = json.loads(data)
        if not lo:
            return None
        tn = TreeNode(lo[0][0])
        q = [tn]

        lvl = 0
        for slv in lo[1:]:
            lvl += 1
            idx = 0
            q2 = []
            #print(slv, len(q))
            for np in q:
                if slv[idx] != "*":
                    np.left = TreeNode(slv[idx])
                    q2.append(np.left)
                idx+=1
                if slv[idx] != "*":
                    np.right = TreeNode(slv[idx])
                    q2.append(np.right)
                idx+=1
                
            q = q2
        return tn
                

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))