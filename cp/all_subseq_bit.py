
def generateSeq(s: str)->None:
    n = len(s)
    for i in range((1 << n)):
        st = []
        for j in range(n):
            if i & (1 << j):
                st.append(s[j])
        
        if st:
            print(st)

if __name__ == "__main__":
    s = input()
    generateSeq(s)
