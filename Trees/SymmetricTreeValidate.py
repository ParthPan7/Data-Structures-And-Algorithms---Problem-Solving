# Question reference : https://leetcode.com/problems/symmetric-tree/
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def checkSymmetric(self,left:TreeNode, right:TreeNode):
        if not left and not right:
            return True
        elif not left or not right:
            return False
        elif left.val != right.val:
            return False
        
        return self.checkSymmetric(left.left,right.right) and self.checkSymmetric(left.right,right.left)
            
    def isSymmetric(self, root: TreeNode) -> bool:
        return self.checkSymmetric(root.left,root.right)
