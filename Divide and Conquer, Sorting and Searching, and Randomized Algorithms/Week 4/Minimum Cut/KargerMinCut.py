import random
import copy

def kargerMinCut(graph):
    while len(graph) > 2:
        vertexAIndex = random.choice(list(graph.keys()))
        vertexBIndex = random.choice(list(graph[vertexAIndex]))
        graph[vertexAIndex].extend(graph[vertexBIndex])
        for vertex in graph[vertexBIndex]:
            graph[vertex].remove(vertexBIndex)
            graph[vertex].append(vertexAIndex)
        while vertexAIndex in graph[vertexAIndex]:
            graph[vertexAIndex].remove(vertexAIndex)
        del graph[vertexBIndex]

    for key in graph.keys():
        length = len(graph[key])
    return length


def main():
    graph = {}

    with open('kargerMinCut.txt', 'r') as graphInput:
        for line in graphInput:
            vertices = [int(vertex) for vertex in line.split()]
            graph[vertices[0]] = vertices[1:]

    print(graph)

    minCut = float('Inf')

    for i in range(100):
        print(i)
        currentCut = kargerMinCut(copy.deepcopy(graph))
        if currentCut < minCut:
            minCut = currentCut
    print(minCut)

if __name__ == "__main__":
    main()