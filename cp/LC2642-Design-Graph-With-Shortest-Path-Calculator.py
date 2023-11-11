from typing import List
from heapq import heappop, heappush


class Graph:
    def __init__(self, n: int, edges: List[List[int]]):
        self.adjList = [[] for _ in range(n)]
        for u, v, w in edges:
            self.adjList[u].append([v, w])

        print(self.adjList)

    def addEdge(self, edge: List[int]) -> None:
        self.adjList[edge[0]].append([edge[1], edge[2]])

    def shortestPath(self, node1: int, node2: int) -> int:
        n = len(self.adjList)

        pq = [(0, node1)]
        dist = [1e9] * (n)
        dist[node1] = 0

        while pq:
            wt, u = heappop(pq)

            if wt > dist[u]:
                continue
            if u == node2:
                return wt

            for v, w in self.adjList[u]:
                if wt + w < dist[v]:
                    dist[v] = wt + w
                    heappush(pq, (dist[v], v))

        return -1


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
