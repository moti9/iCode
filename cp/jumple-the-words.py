
def jumbleWords(word1:str, word2:str) ->str:
    result,extra, n = "","",0
    if(len(word1)>len(word2)):
        n=len(word2)
        extra=word1[n:]
    if(len(word1)<=len(word2)):
        n=len(word1)
        extra=word2[n:]
    for i in range(n):
        result+=word1[i]
        result+=word2[i]
    
    return result+extra 

if __name__ == "__main__":
    word1 = input()
    word2 = input()
    print(jumbleWords(word1,word2))