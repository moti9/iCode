class Solution(object):

    def isPal(self, s):
        return s == s[::-1]

    def partitionOfStr(self, s, ds, ans):
        if not s:
            ans.append(ds)
            return

        for i in range(1, len(s) + 1):
            if self.isPal(s[:i]):
                self.partitionOfStr(s[i:], ds + [s[:i]], ans)

    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        ans = []
        self.partitionOfStr(s, [], ans)
        return ans


def main():
    s = input()
    sol = Solution()
    ans = sol.partition(s)

    for ls in ans:
        print(ls)


if __name__ == "__main__":
    main()
