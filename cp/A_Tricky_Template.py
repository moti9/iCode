def solve_template(t, test_cases):
    for _ in range(t):
        n = test_cases[_][0]
        a = test_cases[_][1]
        b = test_cases[_][2]
        c = test_cases[_][3]

        # Check if there exists a template
        template_exists = True
        for i in range(n):
            # If both a and b are same, and c is different, template exists
            if a[i] == b[i] and a[i] != c[i]:
                continue
            # If a and b are different, and c is same, template exists
            elif a[i] != b[i] and a[i] == c[i]:
                continue
            # If both a and b are different, and c is different, template exists
            elif a[i] != b[i] and a[i] != c[i] and b[i] != c[i]:
                continue
            else:
                template_exists = False
                break

        # Output result for the current test case
        if template_exists:
            print("YES")
        else:
            print("NO")

# Input reading
t = int(input())
test_cases = []
for _ in range(t):
    n = int(input())
    a = input()
    b = input()
    c = input()
    test_cases.append((n, a, b, c))

# Call the function to solve the problem
solve_template(t, test_cases)
