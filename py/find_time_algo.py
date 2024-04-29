import time
from memory_profiler import memory_usage
import heapq
import networkx as nx

# Create a simple weighted graph for pathfinding algorithms
def create_graph():
    G = nx.DiGraph()
    edges = [
        ('A', 'B', 1), ('B', 'C', 2), ('A', 'D', 4),
        ('D', 'E', 2), ('C', 'E', 1), ('E', 'F', 3),
        ('B', 'F', 7)
    ]
    G.add_weighted_edges_from(edges)
    return G

# A* algorithm implementation
def a_star(graph, start, goal):
    def heuristic(u, v):
        return 0  # Zero heuristic for simplicity (turns into Dijkstra's essentially)

    frontier = [(0, start, ())]  # priority queue
    explored = set()

    while frontier:
        cost, node, path = heapq.heappop(frontier)
        if node in explored:
            continue

        path = (node, path)
        if node == goal:
            return (cost, path)

        explored.add(node)
        for neighbor, data in graph[node].items():
            if neighbor in explored:
                continue
            priority = cost + data['weight']
            heapq.heappush(frontier, (priority, neighbor, path))

    return float("inf"), None

# Dijkstra's algorithm implementation
def dijkstra(graph, start, goal):
    frontier = [(0, start, ())]  # priority queue
    explored = set()

    while frontier:
        cost, node, path = heapq.heappop(frontier)
        if node in explored:
            continue
        
        path = (node, path)
        if node == goal:
            return (cost, path)
        
        explored.add(node)
        for neighbor, data in graph[node].items():
            if neighbor in explored:
                continue
            priority = cost + data['weight']
            heapq.heappush(frontier, (priority, neighbor, path))
    
    return float("inf"), None

# Measure algorithm performance
def measure_performance(func, *args):
    start_time = time.time()
    mem_usage = memory_usage((func, args), interval=0.1, timeout=1)
    end_time = time.time()
    
    return end_time - start_time, max(mem_usage) - min(mem_usage)

# Main execution setup
graph = create_graph()
start, goal = 'A', 'F'

# A* performance
a_star_time, a_star_mem = measure_performance(a_star, graph, start, goal)
print("A* Time: {:.6f} sec, Memory: {:.2f} MiB".format(a_star_time, a_star_mem))

# Dijkstra's performance
dijkstra_time, dijkstra_mem = measure_performance(dijkstra, graph, start, goal)
print("Dijkstra Time: {:.6f} sec, Memory: {:.2f} MiB".format(dijkstra_time, dijkstra_mem))
