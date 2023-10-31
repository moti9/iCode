def max_consecutive_lighthouses(n, positions):
    positions.sort()  # Sort the positions in ascending order
    max_consecutive = 0
    consecutive = 1

    for i in range(1, n):
        if positions[i] - positions[i - 1] <= 1:
            consecutive += 1
        else:
            max_consecutive = max(max_consecutive, consecutive)
            consecutive = 1

    max_consecutive = max(max_consecutive, consecutive)  # Check the last group

    return max_consecutive

def main():
    n = int(input())
    positions = list(map(int, input().split()))
    result = max_consecutive_lighthouses(n, positions)
    print(result)

if __name__ == "__main__":
    main()

# Example usage:
# n = 7
# positions = [1, 2, 4, 6, 7, 9, 10]


