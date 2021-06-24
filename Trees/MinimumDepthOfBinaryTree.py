# https://leetcode.com/problems/minimum-depth-of-binary-tree/

minheight = 1000000
    def traverseTreeInOrder(self, root: TreeNode, depth):
        if not root:
            return
        if not root.left and not root.right:
            self.minheight = min(self.minheight, depth)
            return
        if root.left:
            self.traverseTreeInOrder(root.left, depth+1)
        if root.right:
            self.traverseTreeInOrder(root.right, depth+1)
        return 
    def minDepth(self, root: TreeNode) -> int:
        self.traverseTreeInOrder(root,1)
        return 0 if self.minheight == 1000000 else self.minheight
