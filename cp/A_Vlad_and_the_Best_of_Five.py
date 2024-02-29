
if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        s = input()
        if s.count('A') > s.count('B'):
            print('A')
        else:
            print('B')