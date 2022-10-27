import sys
#sys.stdin = open("./14888/input.txt", "r")

def calculate(dep, answer, p, s, m, d):
    global maximum, minimum
    if dep == N:
        maximum = max(answer, maximum)
        minimum = min(answer, minimum)

    if p:
        calculate(dep + 1, answer + num[dep], p - 1, s, m, d)
    if s:
        calculate(dep + 1, answer - num[dep], p, s - 1, m, d)
    if m:
        calculate(dep + 1, answer * num[dep], p, s, m - 1, d)
    if d:
        calculate(dep + 1, int(answer / num[dep]), p, s, m, d - 1)

N = int(input())
num = list(map(int, input().split()))
ope = list(map(int, input().split()))

minimum, maximum = 1000000000, -1000000000

calculate(1, num[0], ope[0], ope[1], ope[2], ope[3])

print(maximum)
print(minimum)

