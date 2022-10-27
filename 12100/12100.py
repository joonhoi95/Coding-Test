from copy import deepcopy

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
                    tmp_borad[i][now] = weight * 2
                    weight = 0
                    now += 1
                else:
                    tmp_borad[i][now] = weight
                    weight = tmp_borad[i][j]
                    now += 1

            tmp_borad[i][j] = 0
        if weight != 0:
            tmp_borad[i][now] = weight
    return tmp_borad

def move_right(tmp_borad):
    for i in range(n):

        now = n - 1
        weight = 0

        for j in range(n - 1, -1, -1):
            if tmp_borad[i][j] == 0: continue

            if weight == 0:
                weight = tmp_borad[i][j]
            else:
                if weight == tmp_borad[i][j]:
                    tmp_borad[i][now] = weight * 2
                    weight = 0
                    now -= 1
                else:
                    tmp_borad[i][now] = weight
                    weight = tmp_borad[i][j]
                    now -= 1

            tmp_borad[i][j] = 0
        if weight != 0:
            tmp_borad[i][now] = weight
    return tmp_borad



def move_up(tmp_borad):
    for i in range(n):

        now = 0
        weight = 0

        for j in range(n):
            if tmp_borad[j][i] == 0: continue

            if weight == 0:
                weight = tmp_borad[j][i]
            else:
                if weight == tmp_borad[j][i]:
                    tmp_borad[now][i] = weight * 2
                    weight = 0
                    now += 1
                else:
                    tmp_borad[now][i] = weight
                    weight = tmp_borad[j][i]
                    now += 1

            tmp_borad[j][i] = 0
        if weight != 0:
            tmp_borad[now][i] = weight

    return tmp_borad

def move_down(tmp_borad):
    for i in range(n):

        now = n-1
        weight = 0

        for j in range(n-1, -1, -1):
            if tmp_borad[j][i] == 0: continue

            if weight == 0:
                weight = tmp_borad[j][i]
            else:
                if weight == tmp_borad[j][i]:
                    tmp_borad[now][i] = weight * 2
                    weight = 0
                    now -= 1
                else:
                    tmp_borad[now][i] = weight
                    weight = tmp_borad[j][i]
                    now -= 1

            tmp_borad[j][i] = 0
        if weight != 0:
            tmp_borad[now][i] = weight
    return tmp_borad

def solution(tmp_borad, cnt):
    global answer
    # cnt가 5라면 끝
    if cnt == 5:
        for i in range(n):
            answer = max(answer, max(tmp_borad[i]))
        return

    solution(move_right(deepcopy(tmp_borad)), cnt + 1)
    solution(move_left(deepcopy(tmp_borad)), cnt + 1)
    solution(move_up(deepcopy(tmp_borad)), cnt + 1)
    solution(move_down(deepcopy(tmp_borad)), cnt + 1)

n = int(input())
answer = 0
board = [list(map(int, input().split())) for _ in range(n)]
solution(board, 0)
print(answer)


board = [[0 for _ in range(3)] for _ in range(3)]
type(board)



print(board[0])
