from typing import List


class Graph:
    def __init__(self, n: int, edges: List[List[int]]):
        self.adjList = [[1e9] * n for _ in range(n)]
        for edge in edges:
            self.adjList[edge[0]][edge[1]] = edge[2]

        for i in range(n):
            self.adjList[i][i] = 0

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    self.adjList[i][j] = min(
                        int(self.adjList[i][j]),
                        int(self.adjList[i][k]) + int(self.adjList[k][j]),
                    )

    def addEdge(self, edge: List[int]) -> None:
        n = len(self.adjList)
        for i in range(n):
            for j in range(n):
                self.adjList[i][j] = min(
                    int(self.adjList[i][j]),
                    int(self.adjList[i][edge[0]])
                    + int(self.adjList[edge[1]][j])
                    + edge[2],
                )

    def shortestPath(self, node1: int, node2: int) -> int:
        return (
            -1
            if int(self.adjList[node1][node2]) == 1e9
            else int(self.adjList[node1][node2])
        )


if __name__ == "__main__":
    edges = [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]
    g = Graph(4, edges)
    print(g.shortestPath(3, 2))
    # return 6. The shortest path from 3 to 2 in the first diagram above is 3 -> 0 -> 1 -> 2 with a total cost of 3 + 2 + 1 = 6.
    print(g.shortestPath(0, 3))
    # return -1. There is no path from 0 to 3.
    g.addEdge([1, 3, 4])
    # We add an edge from node 1 to node 3, and we get the second diagram above.
    print(g.shortestPath(0, 3))
    # return 6. The shortest path from 0 to 3 now is 0 -> 1 -> 3 with a total cost of 2 + 4 = 6.
