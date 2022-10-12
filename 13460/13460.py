from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().rstrip().split())
graph = []

for i in range(n):
    graph.append(list(input().rstrip()))
    for j in range(m):
        if graph[i][j] == 'R':
            rx, ry = i, j
        elif graph[i][j] == 'B':
            bx, by = i, j

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(rx, ry, bx, by):
    q = deque()
    q.append((rx, ry, bx, by))
    visited = []
    visited.append((rx, ry, bx, by))
    cnt = 0

    while q:
        for _ in range(len(q)):
            # cnt 값 우선적으로 판단
            rx, ry, bx, by = q.popleft()
            if cnt > 10:
                print(-1)
                return
            if graph[rx][ry] == 'O':
                print(cnt)
                return

            # 게임이 안끝난 경우

            # 1. 방향 탐색
            for i in range(4):
                #red
                nrx, nry = rx, ry
                while True:
                    nrx += dx[i]
                    nry += dy[i]
                    if graph[nrx][nry] == '#':
                        nrx -= dx[i]
                        nry -= dy[i]
                        break
                    if graph[nrx][nry] == 'O':
                        break

                #blue
                nbx, nby = bx, by

                while True:
                    nbx += dx[i]
                    nby += dy[i]
                    if graph[nbx][nby] == '#':
                        nbx -= dx[i]
                        nby -= dy[i]
                        break
                    if graph[nbx][nby] == 'O':
                        break

                if graph[nbx][nby] == 'O':
                    continue

                # 위치가 같은 경우
                if nrx == nbx and nry == nby:
                    if abs(nrx - rx) + abs(nry - ry) > abs(nbx - bx) + abs(nby - by):
                        nrx -= dx[i]
                        nry -= dy[i]
                    else:
                        nbx -= dx[i]
                        nby -= dy[i]

                if (nrx, nry, nbx, nby) not in visited:
                    q.append((nrx, nry, nbx, nby))
                    visited.append((nrx, nry, nbx, nby))

        cnt += 1

    print(-1)

bfs(rx, ry, bx, by)