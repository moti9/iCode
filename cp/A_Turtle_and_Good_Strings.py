
def main():

    n = int(input())
    s = input()
    print("Yes") if s[0] != s[n - 1] else print("No")

if __name__== "__main__":
    tt = int(input())
    while tt > 0:
        main()
        tt -= 1