from collections import deque

# LeetCode Premium
# https://www.youtube.com/watch?v=e69C6xhiSQE
def wallsAndGates(rooms):
    m, n = len(rooms), len(rooms[0])
    visit = set()
    q = deque()

    def addRoom(i, j):
        if i < 0 or i >= m or j < 0 or j <= n or (i, j) in visit or rooms[i][j] == -1:
            return

        visit.add((i, j))
        q.append([i, j])

    for i in range(m):
        for j in range(n):
            # if it is a gate then add it because we'll only traverse from the gates
            if rooms[i][j] == 0:
                q.append([i, j])
                visit.add((i, j))

    dist = 0
    while q:
        for _ in range(len(q)):
            i, j = q.popleft()
            rooms[i][j] = dist
            addRoom(i + 1, j)
            addRoom(i - 1, j)
            addRoom(i, j + 1)
            addRoom(i, j - 1)
            dist += 1

    return rooms


rooms = [
    [2147483647, -1, 0, 2147483647],
    [2147483647, 2147483647, 2147483647, -1],
    [2147483647, -1, 2147483647, -1],
    [0, -1, 2147483647, 2147483647],
]
print(wallsAndGates(rooms))
