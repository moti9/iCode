# from builtins import str


class Solution:
    def sortVowels(self, s: str) -> str:
        vowel = "AEIOUaeiou"
        count = {}
        for ch in s:
            if ch in vowel:
                count[ch] = count.get(ch, 0) + 1

        j = 0
        ans = ""
        for ch in s:
            if ch in vowel:
                while count.get(vowel[j], 0) == 0:
                    j += 1
                ans += vowel[j]
                count[vowel[j]] -= 1
            else:
                ans += ch

        return ans


def main() -> None:
    s = input()
    sol = Solution()
    print(sol.sortVowels(s))


if __name__ == "__main__":
    main()
