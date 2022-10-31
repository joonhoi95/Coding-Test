#걸린시간 : 40분 -> 시간초과
import sys
#sys.stdin = open("./14889/input.txt", "r")

def solution(answer):
    global minimum
    for i in range(len(answer)):
        for j in range(len(answer)):
            if i == j: continue
            if len(set(check_enrty[i]).intersection(set(check_enrty[j]))) == 0:
                minimum = min(minimum, abs(answer[i]-answer[j]))
    return minimum

def calculate(dep, entry):
    if dep == N/2 and len(entry) == N/2:
        temp = 0
        for i in entry:
            for j in entry:
                temp += board[i][j]
        answer.append(temp)
        check_enrty.append(entry)
    else:
        for k in range(entry[dep-1], N):
            temp_entry = entry.copy()
            if k not in temp_entry:
                temp_entry.append(k)
                calculate(dep+1, temp_entry)

N = int(sys.stdin.readline())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
minimum = 100 * N
answer = list()
check_enrty = list()
for i in range(N):
    entry = list()
    entry.append(i)
    calculate(1, entry)

print(solution(answer))