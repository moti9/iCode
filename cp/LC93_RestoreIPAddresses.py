class Solution:

    def check(self, n, s):
        ls = s.split(".")
        # print(s)
        # print(ls)
        if len(ls) > 4 or len(ls) < 4:
            return False

        tLen = 0
        for x in ls:
            if x == '' or (int(x[0]) == 0 and len(x) > 1) or int(x) > 255:
                return False
            tLen += len(x)
        if tLen != n:
            return False

        return True

    def solve(self, ind, n, st, ds):
        if ind >= n:
            if self.check(n, ds):
                self.ans.append(ds)
                # print(self.ans)
            return
        ds += st[ind]
        self.solve(ind + 1, n, st, ds + '.')
        self.solve(ind + 1, n, st, ds)

    def restoreIpAddresses(self, s: str):
        self.ans = []
        n = len(s)
        if n > 12:
            return self.ans
        ds = ""
        self.solve(0, n, s, ds)

        return self.ans


def main():
    s = input()
    ans = []
    sol = Solution()
    ans = sol.restoreIpAddresses(s)

    for x in ans:
        print(x)


if __name__ == "__main__":
    main()