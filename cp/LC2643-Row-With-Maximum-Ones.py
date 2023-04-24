from ast import List
class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        ans=0
        for arr in mat:
            ans=max(ans,arr.count(1))
        return ans
if __name__=="__main__":
    n,m=map(int,input().split())
    mat=[]
    for _ in range(n):
        a=[int(x) for x in input().split()][:n]
        mat.append(a)
    sol=Solution()
    print(sol.rowAndMaximumOnes(mat))
    