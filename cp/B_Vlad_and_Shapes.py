

if __name__== "__main__":
    tt = int(input())
    for _ in range(tt):
        arr = []
        n = int(input())
        for _ in range(n):
            s = input()
            arr.append(s)
        
        tr = False
        sum = 0
        row, col = 0, -1
        for s in arr:
            tmp = 0
            for r in s:
                if r == '1':
                    tmp += 1
                    sum += 1
            col = max(col, tmp)
            if tmp > 0:
                row += 1

        # sq_rt = int(sum**0.5)

        if row * col == sum:
            print("SQUARE")
        else:
            print("TRIANGLE")