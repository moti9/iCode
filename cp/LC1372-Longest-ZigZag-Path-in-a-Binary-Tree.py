# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
      
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        self.pathLength = 0
        
        def dfs(node, goLeft, steps):
            if node:
                self.pathLength = max(self.pathLength, steps)
                if goLeft:
                    dfs(node.left, False, steps + 1)
                    dfs(node.right, True, 1)
                else:
                    dfs(node.left, False, 1)
                    dfs(node.right, True, steps + 1)
        
        dfs(root, False, 0)
        dfs(root, True, 0)
        return self.pathLength
    
tr=TreeNode(1)
tr.right=TreeNode(2)
tr.right.left=TreeNode(3)
tr.right.left.right=TreeNode(4)
tr.right.left.right.left=TreeNode(5)

sol=Solution()

print(sol.longestZigZag(tr))