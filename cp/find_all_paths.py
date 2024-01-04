def find_paths(start, end, path=[]):
    x, y = start

    # Add current position to the path
    path.append((x, y))

    # If we reach the end point, print the path
    if start == end:
        print("Path found:", path)
    else:
        # Recursively explore all four possible directions
        find_paths((x + 1, y), end, path.copy())  # Right
        find_paths((x - 1, y), end, path.copy())  # Left
        find_paths((x, y + 1), end, path.copy())  # Up
        find_paths((x, y - 1), end, path.copy())  # Down

# Example usage:
start_point = (0, 0)
end_point = (2, 2)

find_paths(start_point, end_point)
