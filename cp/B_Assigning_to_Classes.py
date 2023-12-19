

def solve():
    n = int(input())
    skills = list(map(int, input().split()))

    skills.sort()
    print(skills[n] - skills[n - 1])
    # print(skills)


if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        solve()