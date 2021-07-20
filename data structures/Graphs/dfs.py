graph = {
    "A": ["B", "C", "D"],
    "B": ["E", "F"],
    "C": ["A", "F"],
    "D": ["A"],
    "E": ["B"],
    "F": ["B", "C"],
}


def dfs(node, visited, storeDfs):
    visited.append(node)
    storeDfs.append(node)

    for adj_node in graph[node]:
        if adj_node not in visited:
            dfs(adj_node, visited, storeDfs)


def dfsOfGraph():
    visited = []
    storeDfs = []

    for i in graph:
        if i not in visited:
            dfs(i, visited, storeDfs)

    return storeDfs


print(dfsOfGraph())
