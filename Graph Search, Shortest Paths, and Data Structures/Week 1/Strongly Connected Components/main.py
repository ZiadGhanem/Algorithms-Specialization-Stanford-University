import sys
import threading

NUM_NODES = 875715
finish_time = 0
start = None
explored = None
leader = None
scc_size = 0
sorted_by_finish_time = None

# DFS Loop to calculate the magical order
def dfs_loop_1(reverse_graph):
    global finish_time, explored, sorted_by_finish_time
    finish_time = 0
    explored = [False] * NUM_NODES
    sorted_by_finish_time = [None] * NUM_NODES
    # Loop over nodes in reverse order
    for node in reversed(range(NUM_NODES)):
        if not explored[node]:
            dfs_1(reverse_graph, node)

def dfs_1(reverse_graph, node):
    global finish_time, explored
    explored[node] = True
    for vertex in reverse_graph[node]:
        if not explored[vertex]:
            dfs_1(reverse_graph, vertex)
    sorted_by_finish_time[finish_time] = node
    finish_time += 1

def dfs_loop_2(graph):
    global scc_size, explored, sorted_by_finish_time
    explored = [False] * NUM_NODES
    result = []
    for node in reversed(range(NUM_NODES)):
        if not explored[sorted_by_finish_time[node]]:
            scc_size = 0
            dfs_2(graph, sorted_by_finish_time[node])
            result.append(scc_size)

    return result

def dfs_2(graph, i):
    global explored, scc_size

    explored[i] = True

    for vertex in graph[i]:
        if not explored[vertex]:
            dfs_2(graph, vertex)

    scc_size += 1

def kosaraju_scc(graph, reverse_graph):
    dfs_loop_1(reverse_graph)
    result = dfs_loop_2(graph)
    return result

def main():
    # Graph file
    GRAPH_FILE = "SCC.txt"

    # Create graph and reversed graph adjacency lists
    graph = [[] for i in range(NUM_NODES)]
    reverse_graph = [[] for i in range(NUM_NODES)]

    with open(GRAPH_FILE) as graph_file:
        for line in graph_file.readlines():
            items = line.split()
            graph[int(items[0])] += [int(items[1])]
            reverse_graph[int(items[1])] += [int(items[0])]

    result = kosaraju_scc(graph, reverse_graph)

    print(','.join(map(lambda x: str(x), sorted(result)[::-1][:5])))

if __name__ == "__main__":
    threading.stack_size(67108864)
    sys.setrecursionlimit(2 ** 20)
    thread = threading.Thread(target=main)
    thread.start()




