import java.util.LinkedList;
import java.util.Queue;

/**
 * HeightOfBinaryTree
 */

class Node {
    int val;
    Node left, right;

    Node(int val) {
        this.val = val;
        left = null;
        right = null;
    }
}

class Solution {
    int maxDepthDFS(Node root) {
        if (root == null)
            return 0;
        int lh = maxDepthDFS(root.left);
        int rh = maxDepthDFS(root.right);

        return 1 + Math.max(lh, rh);
    }

    int maxDepthBFS(Node rootNode) {
        if (rootNode == null)
            return 0;

        Queue<Node> queue = new LinkedList<>();
        queue.add(rootNode);

        int level = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Node node = queue.poll();
                if (node.left != null)
                    queue.add(node.left);
                if (node.right != null)
                    queue.add(node.right);
            }
            level++;
        }
        return level;
    }
}

public class HeightOfBinaryTree {
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.left.right.right = new Node(6);
        root.left.right.right.right = new Node(7);

        Solution solution = new Solution();
        int depth = solution.maxDepthDFS(root);
        int depth2 = solution.maxDepthBFS(root);

        System.out.println(depth);
        System.out.println(depth2);
    }
}