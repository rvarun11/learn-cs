graph = {
    "A": ["B", "C", "D"],
    "B": ["E", "F"],
    "C": ["A", "F"],
    "D": ["A"],
    "E": ["B"],
    "F": ["B", "C"],
}


def bfs(node):
    storeBfs = []
    # Mark all the nodes as not visited
    visited = []

    # 1. Create a queue and Apend the node to queue
    queue = [node]
    # 2. Add the node to visited list
    visited.append(node)

    while queue:
        adj_node = queue.pop(0)
        storeBfs.append(adj_node)

        for i in graph[adj_node]:
            if i not in visited:
                queue.append(i)
                visited.append(i)

    return storeBfs


def checkCycle(i, graph, visited) -> bool:
    queue = []
    # Mark the node as visited
    visited.append(i)
    queue.append((i, -1))

    while not queue:
        node = queue[0][0]
        prev = queue[0][1]

        queue.pop(0)

        for adj_node in graph[node]:
            if adj_node not in visited:
                visited.append(adj_node)
                queue.append((adj_node, node))

            elif prev != adj_node:
                return True

    return False


def isCycle(graph) -> bool:
    visited = []

    for i in graph:
        if i not in visited:
            if checkCycle(i, graph, visited):
                return True

    return False


# print(bfs("A"))

print(isCycle(graph))
