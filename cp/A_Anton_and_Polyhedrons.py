def solve():
    face_dict = {
        "Tetrahedron": 4,
        "Cube": 6,
        "Octahedron": 8,
        "Dodecahedron": 12,
        "Icosahedron": 20
    }

    n = int(input())
    ans = 0
    for _ in range(n):
        s = input()
        ans += face_dict.get(s)
    
    print(ans)

solve()