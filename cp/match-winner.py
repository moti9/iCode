def main():
    ar = list(map(int, input().split()))
    br = list(map(int, input().split()))
    ar.sort()
    ans = []
    import bisect

    for i in br:
        count = bisect.bisect(ar, i)
        ans.append(count)

    print(ans)

if __name__ == "__main__":
    main()
