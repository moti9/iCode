import  numpy as np

# CASE-A : If m == n
# Solution for the this type of linear equation can be find out using
# x = A^(-1) @ b

'''
A = np.array([[2, 3], [5, 7]])
b = np.array([7, 10])

print("Rank of the matrix : ", np.linalg.matrix_rank(A))

print("Inverse of the matrix : \n", np.linalg.inv(A))

print("Solution of the equation : \n", np.linalg.solve(A, b))
'''

# Singgular matrix
'''
A = np.array([[2, 3], [4, 6]])
b = np.array([5, 10])

def Solution(A, b):
    if np.linalg.det(A) != 0:
        inv = np.linalg.inv(A)
        sol = inv @ b
        return sol
    else:
        return "Infinite solution"
    
print(Solution(A, b))
'''

# if m > n, No solution
# Solution for the this type of linear equation can be find out using
# x = (A^(T)A)^(-1) @ A^(T) @ b 

'''
A = np.array([[1, 2], [3, 7], [4,9]])
b = np.array([5, 10, 15])

def solution(A, b):
    A_trans = np.transpose(A)
    sol = np.linalg.inv(A_trans@A)@A_trans@b
    return sol

print(solution(A, b))
print(A@solution(A, b))
'''

# if m < n
# Solution for the this type of linear equation can be find out using
# x = A^T @ (A.A^T)^(-1) @ b

A = np.array([[1, 2, 3], [3, 4, 5]])
b =np.array([20,38])

def solve(A, b):
    A_trans = np.transpose(A)
    inv = np.linalg.inv(A@A_trans)
    sol = A_trans@inv@b
    return sol

print(solve(A, b))
print(A@solve(A, b))