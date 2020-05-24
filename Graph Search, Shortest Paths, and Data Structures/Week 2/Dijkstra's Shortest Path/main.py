def main():
    ADJACENCY_LIST = "dijkstraData.txt"
    graph = {}

    with open(ADJACENCY_LIST) as adjacency_list:
        for line in adjacency_list.readlines():
            vertices = line.split()
            graph[int(vertices[0])] = []
            for vertex in vertices[1:]:
                column = vertex.split(',')
                graph[int(vertices[0])].append([int(column[0]), int(column[1])])


    explored_nodes = []
    source_vertex = 1
    explored_nodes.append(source_vertex)
    distance_nodes = {}
    distance_nodes[source_vertex] = 0
    min_distance = float('inf')

    # While all nodes are not yet explored
    while len(explored_nodes) != len(graph):
        # Loop over all vertices which are already explored
        for vertex in graph.keys():
            if vertex in explored_nodes:
                # Loop over their neighbouring nodes which are not yet explored
                for neighbour_node, neighbour_distance in graph[vertex]:
                    if neighbour_node not in explored_nodes:
                        # Choose the node with the total shortest distance
                        l_vw = distance_nodes[vertex] + neighbour_distance
                        if l_vw < min_distance:
                            min_distance = l_vw
                            w_star = neighbour_node
        # Add this node as explored
        explored_nodes.append(w_star)
        # Set its distance
        distance_nodes[w_star] = min_distance
        min_distance = float('inf')

    output = [distance_nodes[index] for index in [7, 37, 59, 82, 99, 115, 133, 165, 188, 197]]
    print(output)
    print("[2599, 2610, 2947, 2052, 2367, 2399, 2029, 2442, 2505, 3068]")





if __name__ == "__main__":
    main()