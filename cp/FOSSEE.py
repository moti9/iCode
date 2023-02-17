# def solve():
#     print("Hii")
#     pass

# if __name__=='__main__':
#     solve()
#     pass


# import numpy as np

# a=np.array([[0,1,2],[3,4,5],[6,7,8]])
# a[0::2]=0
# # an=(a[0::2]=0)
# print(a)
    

# def caesar_cipher(text, shift):
#     result = ""
#     for char in text:
#         result += chr((ord(char) - 97 + shift) % 26 + 97)
#     return result



# import re

# def strip_string(arg):
#     stripped = re.sub(r'[^a-zA-Z0-9/_]+', '_', arg)
#     return re.sub(r'_+', '_', stripped)



class LinearEquation:

    def __init__(self,*args):
        if len(args)==3:
            self.a,self.b,self.c=[float(x) for x in args]
        else:
            self.a=float(0)
            self.b=float(0)
            self.c=float(0)

    def __str__(self):
        return self.__repr__()
        if self.b>=0.0:
            return f"{self.a:.1f}x + {self.b:.1f}y = {self.c:.1f}"
        return f"{self.a:.1f}x - {(-1)*self.b:.1f}y = {self.c:.1f}"

    def __repr__(self):
        if self.b>=0.0:
            return f"{self.a:.1f}x + {self.b:.1f}y = {self.c:.1f}"
        return f"{self.a:.1f}x - {(-1)*self.b:.1f}y = {self.c:.1f}"
        return f"LinearEquation({self.a:.1f}, {self.b:.1f}, {self.c:.1f})"

    def __add__(self, other):
        a = self.a + other.a
        b = self.b + other.b
        c = self.c + other.c
        return LinearEquation(a, b, c)

    def isparallel(self, other):
        if other.a>0.0 and other.b>0.0 and other.c>0.0 and self.a/other.a ==self.b/other.b and self.a/other.a !=self.c/other.c and self.c/other.c !=self.b/other.b:
            return True
        return False

    def intersect(self, other):
        if other.a>0.0 and other.b>0.0 and self.a/other.a !=self.b/other.b:
            return True
        return False


    def overlaps(self, other):
        if other.a>0.0 and other.b>0.0 and other.c>0.0 and self.a/other.a ==self.b/other.b and self.a/other.a ==self.c/other.c and self.c/other.c ==self.b/other.b:
            return True
        return False

eqn=LinearEquation(2,3,5)       
print(eqn)
assert eqn.a==2.0
print(LinearEquation())






# import re

# def strip_string(arg):
#     stripped = re.sub(r'[^a-zA-Z0-9/_]+', '_', arg)
#     return re.sub(r'_+', '_', stripped)



# def sum_all(n):
#     s=0
#     for i in range(2,n+1):
#         if i%2==0:
#             s+=i

#     return s