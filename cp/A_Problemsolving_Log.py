# Function to calculate the number of problems solved in a contest
def solve_contest(n, contest_log):
    time_required = {chr(ord('A') + i): i + 1 for i in range(26)}
    total_time = 0
    solved_problems = 0

    for i in range(n):
        total_time += time_required[contest_log[i]]
        if total_time >= i + 1:
            solved_problems += 1

    return solved_problems

# Main function to handle multiple test cases
def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        contest_log = input().strip()
        result = solve_contest(n, contest_log)
        print(result)

# Run the main function
if __name__ == "__main__":
    main()
