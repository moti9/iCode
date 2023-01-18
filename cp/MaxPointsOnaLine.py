class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        dict={}
        maxi=0
        for i in range(len(points)-max-1):
            mxp=0
            for j in range(i+1,len(points)):
                if (points[j][0]-points[i][0])==0:
                    slope=10000001
                else:
                    slope=(float)(points[j][1]-points[i][1])/(float)(points[j][0]-points[i][0])
                
                if dict.has_key(slope):
                    dict[slope]=dict[slope]+1
                else:
                    dict[slope]=1
                
                mxp= mxp if mxp>dict[slope] else dict[slope]
            dict.clear()
            maxi=maxi if maxi>mxp else mxp
        
        return maxi+1
