def count_attacking_positions(a, b, x1, y1, x2, y2):
    dx = [-1, 1, -1, 1]
    dy = [-1, -1, 1, 1]

    st1 = set()
    st2 = set()

    for i in range(4):
        st1.add((x1 + dx[i] * a, y1 + dy[i] * b))
        st1.add((x1 + dx[i] * b, y1 + dy[i] * a))

        st2.add((x2 + dx[i] * a, y2 + dy[i] * b))
        st2.add((x2 + dx[i] * b, y2 + dy[i] * a))

    return len(st1.intersection(st2))

def main():
    t = int(input())
    
    for _ in range(t):
        a, b = map(int, input().split())
        x1, y1 = map(int, input().split())
        x2, y2 = map(int, input().split())
        
        result = count_attacking_positions(a, b, x1, y1, x2, y2)
        print(result)

if __name__ == "__main__":
    main()
