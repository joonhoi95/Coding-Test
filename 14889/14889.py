#기존 코드와 비교
#for문을 한번만 돌리면 된다 -> 무조건 1팀에는 속해야함
#python 3로 돌리면 오류가 나는데, pypy3로 돌리면 가능함

import sys
#sys.stdin = open("./14889/input.txt", "r")
def bfs(depth, idx):
    global minimum
    if depth == n//2:
        power1, power2 = 0, 0
        for i in range(n):
            for j in range(n):
                if visited[i] and visited[j]:
                    power1 += graph[i][j]
                elif not visited[i] and not visited[j]:
                    power2 += graph[i][j]
        minimum = min(minimum, abs(power1 - power2))
        return

    for i in range(idx, n):
        if not visited[i]:
            visited[i] = True
            bfs(depth+1, i+1)
            visited[i] = False


n = int(input())

visited = [False for _ in range(n)]
graph = [list(map(int, input().split())) for _ in range(n)]
minimum = int(1e9)

bfs(0, 0)
print(minimum)