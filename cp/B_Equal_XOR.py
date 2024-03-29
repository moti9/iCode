

if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))
        freq = [0] * (n + 1)
        for i in range(n):
            freq[arr[i]] += 1

        # print(freq)

        fr0, fr1, fr2 = [], [], []

        for i in range(1, n + 1):
            if freq[i] == 0:
                fr0.append(i)
            elif freq[i] == 1:
                fr1.append(i)
            else:
                fr2.append(i)
        
        sz = 2 * k
        i = 0
        for num in fr2:
            if i < sz:
                i += 2
                print(num, num, end= " ")
            else:
                break

        for num in fr1:
            if i < sz:
                i += 1
                print(num, end= " ")
            else:
                break
        print()

        i = 0

        for num in fr0:
            if i < sz:
                i += 2
                print(num, num, end= " ")
            else:
                break

        for num in fr1:
            if i < sz:
                i += 1
                print(num, end= " ")
            else:
                break
        print()