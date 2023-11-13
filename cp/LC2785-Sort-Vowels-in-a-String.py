# from builtins import str


class Solution:
    def sortVowels(self, s: str) -> str:
        vowel = "AEIOUaeiou"
        temp = []
        for ch in s:
            if ch in vowel:
                temp.append(ch)
        temp.sort()

        j = 0
        ans = ""
        for ch in s:
            if ch in vowel:
                ans += temp[j]
                j += 1
            else:
                ans += ch

        return ans


def main() -> None:
    s = input()
    sol = Solution()
    print(sol.sortVowels(s))


if __name__ == "__main__":
    main()
