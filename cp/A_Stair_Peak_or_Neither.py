if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        a, b, c = map(int, input().split())
        if a < b < c:
            print("STAIR")
        elif a < b > c:
            print("PEAK")
        else:
            print("NONE")