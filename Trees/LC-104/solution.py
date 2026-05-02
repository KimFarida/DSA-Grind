# LC104. Maximum Depth of Binary Tree
# Approach: DFS recursive
# Time: O(n) | Space: O(h) where h is tree height

class Solution:
    def maxDepth(self, root):
        if not root:
            return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))