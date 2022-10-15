from collections import deque

def solution():
    global answer
    global board

    #뱀의 위치 표시 -> 시작과 끝!
    snake = deque([(0,0)])
    x, y, direction = 0, 0, 0

    while True:
        answer += 1
        # 움직여
        x, y = x + dx[direction], y + dy[direction]

        if not 0 <= x < N or not 0 <= y < N or board[x][y] == 1:
            break

        #죽은 상황이 아니면, 무조건 표기
        if board[x][y] == 2:
            board[x][y] = 1
            snake.append((x, y))
        elif board[x][y] == 0:
            snake.append((x,y))
            board[x][y] = 1
            #지나간 자리 지워
            px, py = snake.popleft()
            board[px][py] = 0

        #방향 설정
        if answer in way:
            direction = (direction + way[answer]) % 4

# input 부분
N = int(input())
board = [[0] * N for _ in range(N)]

K = int(input())
for _ in range(K):
    i, j = map(int, input().split())
    board[i-1][j-1] = 2

l = int(input())
way = dict()
for _ in range(l):
    s, d = input().split()
    way[int(s)] = 1 if d == "D" else -1

answer = 0
dx = (0, 1, 0 ,-1)
dy = (1, 0, -1 ,0)

solution()
print(answer)
