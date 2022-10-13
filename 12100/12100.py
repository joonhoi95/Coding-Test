import sys
from copy import deepcopy #library를 안쓰기로 결정!
input = sys.stdin.readline

n = int(input().strip())

answer = 0

board = [list(map(int, input().strip().split())) for _ in range(n)]

def solution(tmp_borad, cnt):

        # (x, y 모두 움직일 수 있도록)
        # 블록이 1개라면 끝
        # cnt가 5라면 끝
        # max 값을 기록

solution(board, 0)
print(answer)







