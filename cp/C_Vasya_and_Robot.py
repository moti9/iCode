def make_move(pos, move, dis) -> None:
    if move == 'D':
        pos[1] -= dis
    elif move == 'U':
        pos[1] += dis
    elif move == 'L':
        pos[0] -= dis
    else:
        pos[0] += dis


def can_move(u, v, sln) -> bool:
    dist = abs(u[0] - v[0]) + abs(u[1] - v[1])
    if dist % 2 != sln % 2:
        return False
    return sln >= dist


def solve(s: str, n: int, x: int, y: int, sln: int) -> bool:
    pos = [0, 0]
    for i in range(sln, n):
        make_move(pos, s[i], 1)

    l, r = 0, sln
    while True:
        if can_move(pos, [x, y], sln):
            return True
        
        if r == n:
            break

        make_move(pos, s[l], 1)
        make_move(pos, s[r], -1)
        l += 1
        r += 1

    return False


if __name__ == "__main__":
    n = int(input())
    s = input()
    x, y = map(int, input().split())

    if not solve(s, n, x, y, n):
        print(-1)
    else:
        l, r = 0, n - 1
        ans = 0
        while l <= r:
            mid = (l + r) // 2
            if solve(s, n, x, y, mid):
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        print(ans)

