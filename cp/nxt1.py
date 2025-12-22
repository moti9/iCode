def main():
    n, k = map(int, input().split())
    bx, by = map(int, input().split())
    
    blocked = set()
    for _ in range(k):
        x, y = map(int, input().split())
        blocked.add((x, y))

    cnt = 0
    directions = [(1,1), (1,-1), (-1,1), (-1,-1)]

    for dx, dy in directions:
        ti, tj = bx, by
        while True:
            ti += dx
            tj += dy
            if ti < 1 or tj < 1 or ti > n or tj > n:
                break
            if (ti, tj) in blocked:
                break
            cnt += 1

    print(cnt)

if __name__ == "__main__": 
    main()





# def main():
#     n, k = map(int, input().split())
#     bx, by = map(int, input().split())
#     matrix = [
#         [0 for j in range(n)]
#         for i in range(n)
#     ]
    
#     for _ in range(k):
#         x, y = map(int, input().split())
#         x -= 1
#         y -= 1
#         matrix[x][y] = 1
    
#     cnt = 0
#     ti, tj = bx - 1, by - 1
#     # right diagonal
#     while True:
#         ti += 1
#         tj += 1
#         if ti >= n or tj >= n:
#             break
#         if matrix[ti][tj] == 0:
#             cnt += 1
#     ti, tj = bx - 1, by - 1
#     # left diagonal
#     while True:
#         ti += 1
#         tj -= 1
#         if ti >= n or tj < 0:
#             break
#         if matrix[ti][tj] == 0:
#             cnt += 1

#     ti, tj = bx - 1, by - 1
#     # right diagonal
#     while True:
#         ti -= 1
#         tj += 1
#         if ti < 0 or tj >= n:
#             break
#         if matrix[ti][tj] == 0:
#             cnt += 1

#     ti, tj = bx - 1, by - 1
#     # right diagonal
#     while True:
#         ti -= 1
#         tj -= 1
#         if ti < 0 or tj < 0:
#             break
#         if matrix[ti][tj] == 0:
#             cnt += 1

#     print(cnt)

# if __name__ == "__main__":
#     main()
