from collections import deque

def main():
    n, m, k = map(int, input().split())
    adj = [[] for _ in range(n + 1)]
    for _ in range(m):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
    st = set()
    for _ in range(k):
        a, b, c = map(int, input().split())
        st.add((a, b, c))
    dist = [[0] * (n + 1) for _ in range(n + 1)]
    last = -1
    q = deque([(1, 1)])  
    dist[1][1] = -1  
    found_path = False
    while q:
        node, parent = q.popleft()
        if node == n:
            found_path = True
            last = parent
            break
        for ch in adj[node]:
            if (parent, node, ch) in st or dist[node][ch]:
                continue
            dist[node][ch] = parent
            q.append((ch, node))
    if found_path:
        path = []
        src, dest = last, n
        while src != -1:
            path.append(dest)
            temp = src
            src = dist[temp][dest]
            dest = temp
        path.reverse()
        print(len(path) - 1)
        print(*path)
    else:
        print(-1)

if __name__ == "__main__":
    main()
