from typing import List
from collections import defaultdict


class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        graph = defaultdict(list)

        for x, y in adjacentPairs:
            graph[x].append(y)
            graph[y].append(x)

        root = None
        for node in graph:
            if len(graph[node]) == 1:
                root = node
                break

        nums = []

        def dfs(node, prev):
            nums.append(node)

            for nb in graph[node]:
                if nb != prev:
                    dfs(nb, node)

        dfs(root, None)
        return nums


def main():
    n = int(input())
    # adjPairs = [[int(input()) for x in range(2)] for _ in range(n)]
    adjPairs = []
    for _ in range(n):
        row = list(map(int, input().strip().split()))
        adjPairs.append(row)
    sol = Solution()
    nums = sol.restoreArray(adjPairs)

    for num in nums:
        print(num, end=" ")
    print()


if __name__ == "__main__":
    main()
