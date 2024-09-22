import java.util.LinkedList
import java.util.Queue

class Node(val `val`: Int) {
    var left: Node? = null
    var right: Node? = null
}

class Solution {
    fun maxDepthDFS(root: Node?): Int {
        if (root == null) return 0
        val leftDepth = maxDepthDFS(root.left)
        val rightDepth = maxDepthDFS(root.right)
        return 1 + maxOf(leftDepth, rightDepth)
    }

    fun maxDepthBFS(root: Node?): Int {
        if (root == null) return 0

        val queue: Queue<Node> = LinkedList()
        queue.add(root)

        var level = 0
        while (queue.isNotEmpty()) {
            val size = queue.size
            for (i in 0 until size) {
                val node = queue.poll()
                node.left?.let { queue.add(it) }
                node.right?.let { queue.add(it) }
            }
            level++
        }
        return level
    }
}

fun main() {
    val root = Node(1).apply {
        left = Node(2).apply {
            left = Node(4)
            right = Node(5).apply {
                right = Node(6).apply {
                    right = Node(7)
                }
            }
        }
        right = Node(3)
    }

    val solution = Solution()
    val depthDFS = solution.maxDepthDFS(root)
    val depthBFS = solution.maxDepthBFS(root)

    println("Depth calculated using DFS: $depthDFS")
    println("Depth calculated using BFS: $depthBFS")
}
