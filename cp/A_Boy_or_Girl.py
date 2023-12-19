
def solve() -> None:
    s = input()
    distinct_chars = set(s)
    
    if len(distinct_chars) % 2 == 1:
        print("IGNORE HIM!")
    else:
        print("CHAT WITH HER!")

if __name__ == "__main__":
    solve()




# def solve() -> None:
#     s = input()
#     dst = set()
#     for c in s:
#         dst.add(c)
    
#     if len(dst) & 1:
#         print("IGNORE HIM!")
#     else:
#         print("CHAT WITH HER!")



# if __name__ == "__main__":
#     solve()