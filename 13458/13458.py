import math

room = int(input())
num = list(map(int, input().split()))
main, sub = map(float, input().split())

sub_cnt = 0
for j in range(len(num)):
    if num[j] - main < 0 : continue
    sub_cnt += int(math.ceil((float(num[j] - main)) / float(sub)))

print(sub_cnt+room)