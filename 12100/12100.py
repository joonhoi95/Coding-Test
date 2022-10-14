import copy
import sys
from copy import deepcopy
input = sys.stdin.readline

n = int(input().strip())
answer = 0
board = [list(map(int, input().strip().split())) for _ in range(n)]


# (모든방향 움직일 수 있도록)
def move_left(tmp_borad):
    for i in range(n):

        now = 0
        weight = 0

        for j in range(n):
            if tmp_borad[i][j] == 0 : continue

            if weight == 0:
                weight = tmp_borad[i][j]
            else:
                if weight == tmp_borad[i][j]:
                    tmp_borad[i][now] = weight >> 1
                    weight = 0
                    now += 1
                else:
                    tmp_borad[i][now] = weight
                    weight = tmp_borad[i][j]
                    now += 1

                board[i][j] = 0
                if weight!= 0:
                    board[i][now] = weight

                tmp_borad[i][j - 1] >> 1
                tmp_borad[i][j] = 0

def move_right(tmp_borad):
    for i in range(n):
        for j in range(n):

def move_up(tmp_borad):
    for i in range(n):
        for j in range(n):

def move_down(tmp_borad):
    for i in range(n):
        for j in range(n):

def solution(tmp_borad, cnt):
    global answer
    # cnt가 5라면 끝
    if(cnt == 5):
        for i in range(n):
            answer = max(answer, max(tmp_borad[i]))

        return

    solution(move_right(deepcopy(tmp_borad)), cnt + 1)
    solution(move_left(deepcopy(tmp_borad)), cnt + 1)
    solution(move_up(deepcopy(tmp_borad)), cnt + 1)
    solution(move_down(deepcopy(tmp_borad)), cnt + 1)

solution(board, 0)
print(answer)