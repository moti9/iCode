if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        n = int(input())
        sh, sd = "##", ".."

        flag = True
        for _ in range(n):
            for _ in range(2):
                temp = flag
                for _ in range(n):
                    if temp:
                        print(sh, end="")
                    else:
                        print(sd, end="")
                    temp = not temp
                print()
            flag = not flag
        
        