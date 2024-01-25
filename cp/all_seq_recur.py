
def generateAllSubSeq(s: str) -> None:
    ds = []
    generateSeq(0, s, ds)

def generateSeq(i: int, s: str, ds)->None:
    if i == len(s):
        if ds:
            print(ds)
        return
    
    generateSeq(i + 1, s, ds)
    ds.append(s[i])
    generateSeq(i + 1, s, ds)
    ds.pop()

if __name__ == "__main__":
    s = input()
    generateAllSubSeq(s)
