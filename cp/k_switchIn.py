def min_steps_to_k_switching(N, S):
    # Find the factors of N
    factors = [i for i in range(1, N+1) if N % i == 0]

    min_steps = float('inf')

    # Check each factor
    for K in factors:
        steps = 0
        for i in range(N):
            # Check if this position should be 0 or 1 based on K
            if (i // K) % 2 == 0:
                if S[i] != '0':
                    steps += 1
            else:
                if S[i] != '1':
                    steps += 1
        min_steps = min(min_steps, steps)

    return min_steps

# Example usage:
N = 16  # Replace with your N
S = "1000111101010111"  # Replace with your string
result = min_steps_to_k_switching(N, S)
print(result)
