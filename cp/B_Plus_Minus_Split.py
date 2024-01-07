def min_penalty(t, test_cases):
    results = []
    
    for _ in range(t):
        n = test_cases[_][0]
        s = test_cases[_][1]

        # Initialize an array to store the cumulative sums
        cumulative_sums = [0] * (n + 1)

        # Calculate cumulative sums
        for i in range(1, n + 1):
            cumulative_sums[i] = cumulative_sums[i - 1] + (1 if s[i - 1] == '+' else -1)

        # Initialize the dp array for dynamic programming
        dp = [float('inf')] * (n + 1)
        dp[0] = 0

        # Dynamic programming to find the minimum penalty
        for i in range(1, n + 1):
            for j in range(i):
                dp[i] = min(dp[i], dp[j] + abs(cumulative_sums[i] - cumulative_sums[j]))

        results.append(dp[n])

    return results

# Input reading and function call
t = int(input())
test_cases = []
for _ in range(t):
    n = int(input())
    s = input()
    test_cases.append((n, s))

results = min_penalty(t, test_cases)

# Output the results
for result in results:
    print(result)
