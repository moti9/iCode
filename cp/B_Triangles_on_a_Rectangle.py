for _ in range(int(input())):
  w, h = map(int, input().split())
  ans = 0
  for i in range(4):
    # k=int(input())
    a = [int(x) for x in input().split()][1:]
    ans = max(ans, (a[-1] - a[0]) * (h if i < 2 else w))
  print(ans)