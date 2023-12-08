def main():
    dis = list(map(int, input().split()))
    dis.sort()

    print(dis[2] - dis[0])

main()