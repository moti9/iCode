from queue import Queue

class Node:
    def __init__(self, val) -> None:
        self.val = val
        self.left = None
        self.right = None

class Solution:
    def maxDepth(self, root):
        if root == None:
            return 0
        
        q = Queue()
        q.put(root)

        level = 0

        while not q.empty():
            size = q.qsize()

            for _ in range(size):
                node = q.get()

                if node.left is not None:
                    q.put(node.left)
                if node.right is not None:
                    q.put(node.right)

            level += 1
        
        return level
    

if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.left.right.right = Node(6)
    root.left.right.right.right = Node(7)

    sol = Solution()
    depth = sol.maxDepth(root)

    print(depth)
        